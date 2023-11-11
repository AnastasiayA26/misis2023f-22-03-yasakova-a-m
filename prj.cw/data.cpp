#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

enum VisualizationType {
    POINTS,
    ARCS,
    VECTORS
};

struct PolarDataPoint {
    double radius, angle;
};

struct CoordinateLimits {
    double maxRadius;
    double maxAngle;
};

std::string getTypeName(VisualizationType visType) {
    switch (visType) {
        case POINTS:
            return "points";
        case ARCS:
            return "arcs";
        case VECTORS:
            return "vectors";
        default:
            return "unknown";
    }
}

std::vector<PolarDataPoint> generatePointsWithNoise(int numPoints, const CoordinateLimits& limits, double noiseLevel) {
    std::vector<PolarDataPoint> data;

    for (int i = 0; i < numPoints; ++i) {
        PolarDataPoint point;
        point.radius = static_cast<double>(rand()) / RAND_MAX * limits.maxRadius;
        point.angle = static_cast<double>(rand()) / RAND_MAX * limits.maxAngle;

        point.radius += noiseLevel * static_cast<double>(rand()) / RAND_MAX;
        point.angle += noiseLevel * static_cast<double>(rand()) / RAND_MAX;

        data.push_back(point);
    }

    return data;
}

std::vector<PolarDataPoint> generateArcsWithNoise(int numArcs, const CoordinateLimits& limits, double noiseLevel) {
    std::vector<PolarDataPoint> data;

    for (int i = 0; i < numArcs; ++i) {
        PolarDataPoint start, end;
        start.radius = static_cast<double>(rand()) / RAND_MAX * limits.maxRadius;
        start.angle = static_cast<double>(rand()) / RAND_MAX * limits.maxAngle;
        end.radius = static_cast<double>(rand()) / RAND_MAX * limits.maxRadius;
        end.angle = static_cast<double>(rand()) / RAND_MAX * limits.maxAngle;

        start.radius += noiseLevel * static_cast<double>(rand()) / RAND_MAX;
        start.angle += noiseLevel * static_cast<double>(rand()) / RAND_MAX;
        end.radius += noiseLevel * static_cast<double>(rand()) / RAND_MAX;
        end.angle += noiseLevel * static_cast<double>(rand()) / RAND_MAX;

        data.push_back(start);
        data.push_back(end);
    }

    return data;
}

std::vector<PolarDataPoint> generateVectorsWithNoise(int numVectors, const CoordinateLimits& limits, double noiseLevel) {
    std::vector<PolarDataPoint> data;

    for (int i = 0; i < numVectors; ++i) {
        PolarDataPoint point;
        point.radius = static_cast<double>(rand()) / RAND_MAX * limits.maxRadius;
        point.angle = static_cast<double>(rand()) / RAND_MAX * limits.maxAngle;

        point.radius += noiseLevel * static_cast<double>(rand()) / RAND_MAX;
        point.angle += noiseLevel * static_cast<double>(rand()) / RAND_MAX;

        data.push_back(point);
    }

    return data;
}

std::vector<PolarDataPoint> generateDataWithNoise(int numObjects, VisualizationType visType, const CoordinateLimits& limits, double noiseLevel) {
    if (visType == POINTS) {
        return generatePointsWithNoise(numObjects, limits, noiseLevel);
    }
    else if (visType == ARCS) {
        return generateArcsWithNoise(numObjects, limits, noiseLevel);
    }
    else if (visType == VECTORS) {
        return generateVectorsWithNoise(numObjects, limits, noiseLevel);
    }
    else {
        std::cerr << "Invalid visualization type" << std::endl;
        return {};
    }
}

bool isNumber(const std::string& str) {
    std::istringstream iss(str);
    double dummy;
    return static_cast<bool>(iss >> dummy);
}


void writeToFile(const std::vector<PolarDataPoint>& data, const std::string& filename) {
    std::ofstream file(filename);

    if (file.is_open()) {
        // Установка точности вывода до двух знаков после запятой
        file << std::fixed << std::setprecision(2);

        for (size_t i = 0; i < data.size(); i += 2) {
            // Запись начала дуги (или вектора)
            file << data[i].radius << " " << data[i].angle << " ";

            // Запись конца дуги (или вектора)
            file << data[i + 1].radius << " " << data[i + 1].angle << std::endl;
        }

        file.close();
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

std::vector<PolarDataPoint> readDataFromFile(const std::string& filename) {
    std::vector<PolarDataPoint> data;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return data;
    }

    double radius, angle;
    while (file >> radius >> angle) {
        data.push_back({radius, angle});
    }

    file.close();
    return data;
}

void writePointsToFile(const std::vector<PolarDataPoint>& data, const std::string& filename) {
    std::ofstream file(filename);

    if (file.is_open()) {
        // Установка точности вывода до двух знаков после запятой
        file << std::fixed << std::setprecision(2);

        for (const auto& point : data) {
            // Запись координаты точки
            file << point.radius << " " << point.angle << std::endl;
        }

        file.close();
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

std::vector<PolarDataPoint> readPointsFromFile(const std::string& filename) {
    std::vector<PolarDataPoint> data;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return data;
    }

    double radius, angle;
    while (file >> radius >> angle) {
        data.push_back({radius, angle});
    }

    file.close();
    return data;
}

int main(int argc, char* argv[]) {
    srand(static_cast<unsigned int>(time(nullptr)));

    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <visType> <numObjects> <noiseLevel>" << std::endl;
        return 1;
    }

    std::string visTypeString = argv[1];
    std::string numObjectsString = argv[2];
    std::string noiseLevelString = argv[3];

    if (!isNumber(numObjectsString) || !isNumber(noiseLevelString)) {
        std::cerr << "Invalid input for numObjects or noiseLevel" << std::endl;
        return 1;
    }

    int numObjects = std::stoi(numObjectsString);

    if (numObjects > 1000000) {
        std::cerr << "Error: numObjects exceeds the maximum allowed value (1000000)" << std::endl;
        return 1;
    }

    double noiseLevel = std::stod(noiseLevelString);

    VisualizationType visType;

    if (visTypeString == "points") {
        visType = POINTS;
    } else if (visTypeString == "arcs") {
        visType = ARCS;
    } else if (visTypeString == "vectors") {
        visType = VECTORS;
    } else {
        std::cerr << "Invalid visualization type" << std::endl;
        return 1;
    }

    CoordinateLimits limits;
    limits.maxRadius = 10.0;
    limits.maxAngle = 2.0 * M_PI;

    std::string typeName = getTypeName(visType);
    std::vector<PolarDataPoint> dataWithNoise = generateDataWithNoise(numObjects, visType, limits, noiseLevel);

    if (visType == POINTS) {
        writePointsToFile(dataWithNoise, typeName + "_data.txt");
    } else if (visType == ARCS || visType == VECTORS) {
        writeToFile(dataWithNoise, typeName + "_data.txt");
    }

    return 0;
}







