#include <data/data.hpp>
#include <random>
#include <iostream>
#include <fstream>
#include <iomanip>

Data::Data() : distribution(0.0, 1.0), lengthDistribution(0.0, 5.0) {
}

void Data::writeSegmentsToFile(const std::vector<Point>& coordinates, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    outFile << std::fixed << std::setprecision(2);

    for (size_t i = 0; i < coordinates.size(); i += 2) {
        outFile << coordinates[i].x << " " << coordinates[i].y << " ";
        outFile << coordinates[i + 1].x << " " << coordinates[i + 1].y << std::endl;
    }

    outFile.close();
}

void Data::writePointsToFile(const std::vector<Point>& coordinates, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    outFile << std::fixed << std::setprecision(2);

    for (const auto& point : coordinates) {
        outFile << point.x << ' ' << point.y << '\n';
    }
    outFile.close();
}

// из одной точки рисуется несколько
void Data::generateSegmentsFromPoint(int numSegments, double noiseStd, const Point& start, const Point& end) {
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0.0, noiseStd);

    std::vector<Point> segments;

    for (int i = 0; i < numSegments; ++i) {
        int segmentLength = distribution(generator) + 10;

        double deltaX = (end.x - start.x) / (segmentLength - 1);
        double deltaY = (end.y - start.y) / (segmentLength - 1);

        Point segmentStart = start;
        Point segmentEnd;

        segmentEnd.x = start.x + (segmentLength - 1) * deltaX + distribution(generator);;
        segmentEnd.y = start.y + (segmentLength - 1) * deltaY + distribution(generator);
        segments.push_back(segmentStart);
        segments.push_back(segmentEnd);
    }
    writeSegmentsToFile(segments, "segment_from_point.txt");
}

void Data::generateSegments(int numPoints, double noiseStd, const Point& start, const Point& end) {
    std::vector<Point> noisyPoints;
    double deltaX = (end.x - start.x) / (numPoints - 1);
    double deltaY = (end.y - start.y) / (numPoints - 1);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> distribution(0.0, noiseStd);
//    Point p;
//    noisyPoints.push_back(p);
    for (int j = 0; j < numPoints; ++j) {
        Point p;
        p.x = start.x + j * deltaX;
        p.y = start.y + j * deltaY;
        noisyPoints.push_back(p);
        p.x = start.x + j * deltaX + distribution(gen);
        p.y = start.y + j * deltaY + distribution(gen);
        noisyPoints.push_back(p);
    }
    writeSegmentsToFile(noisyPoints, "segments.txt");
}

// из одной точки но с разной длиной
void Data::generateSegmentsWithDidLen(int numSegments, double noiseStd, const Point& start, const Point& end, double minLength, double maxLength) {
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0.0, noiseStd);
    std::uniform_real_distribution<double> lengthDistribution(minLength, maxLength);

    std::vector<Point> segments;

    double mainSegmentLength = std::hypot(end.x - start.x, end.y - start.y) / 3;
    double angle = M_PI / 3.0;  // Угол поворота 60


    for (int j = 0; j < numSegments; ++j) {
        Point nestedSegmentStart;
        nestedSegmentStart.x = start.x + j * (mainSegmentLength / numSegments) * cos(angle);
        nestedSegmentStart.y = start.y + j * (mainSegmentLength / numSegments) * sin(angle);

        Point nestedSegmentEnd;
        double randomLength = lengthDistribution(generator);
        nestedSegmentEnd.x = nestedSegmentStart.x + randomLength * cos(angle) + distribution(generator);
        nestedSegmentEnd.y = nestedSegmentStart.y + randomLength * sin(angle) + distribution(generator);

        segments.push_back(nestedSegmentStart);
        segments.push_back(nestedSegmentEnd);
    }

    writeSegmentsToFile(segments, "segments_from_point_with_dif_len.txt");
}
void Data::generateRepeatSegments(int numSegments, double noiseStd, const Point& start, const Point& end) {
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0.0, noiseStd);

    std::vector<Point> resultPoints;
    for (int i = 0; i < numSegments; ++i) {
        Point noisyStart;
        noisyStart.x = start.x + distribution(generator);
        noisyStart.y = start.y + distribution(generator);

        Point noisyEnd;
        noisyEnd.x = end.x + distribution(generator);
        noisyEnd.y = end.y + distribution(generator);

        resultPoints.push_back(noisyStart);
        resultPoints.push_back(noisyEnd);
    }

    writeSegmentsToFile(resultPoints, "repeat_segments.txt");
}


std::vector<Data::SegmentsCoordinates> Data::readPointsFromFile(const char* filename) {
    std::vector<SegmentsCoordinates> coordinates;
    double x, y;

    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Ошибка при открытии файла." << std::endl;
        return coordinates;
    }

    while (inputFile >> x >> y) {
        SegmentsCoordinates coord{ x, y };
        coordinates.push_back(coord);
    }

    inputFile.close();
    return coordinates;
}

std::vector<Data::SegmentsCoordinates> Data::readSegmentsFromFile(const char* filename) {
    std::vector<SegmentsCoordinates> vectors;
    double x, y, z, w;

    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Ошибка при открытии файла." << std::endl;
        return vectors;
    }

    while (inputFile >> x >> y >> z >> w) {
        SegmentsCoordinates coordinates{ x, y, z, w };
        vectors.push_back(coordinates);
    }

    inputFile.close();
    return vectors;
}
