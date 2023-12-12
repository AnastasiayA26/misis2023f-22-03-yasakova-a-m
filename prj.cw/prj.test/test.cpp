#include <data/data.hpp>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 8) {
        std::cerr << "Usage: " << argv[0] << " <type> <numPoints> <blurCoefficient> <startX> <startY> <endX> <endY>" << std::endl;
        return 1;
    }

    Data data;

    std::string type = argv[1];
    int numPoints = std::stoi(argv[2]);
    double blurCoefficient = std::stod(argv[3]);
    double startX = std::stod(argv[4]);
    double startY = std::stod(argv[5]);
    double endX = std::stod(argv[6]);
    double endY = std::stod(argv[7]);

    Data::Point startPoint{ startX, startY };
    Data::Point endPoint{ endX, endY };


    if (type == "segment_from_point") {
       data.generateSegmentsFromPoint(numPoints, blurCoefficient, startPoint, endPoint);
//        std::vector<Data::SegmentsCoordinates> readVectors = data.readSegmentsFromFile("noisy_segments_from_point.txt");
//        for (const auto& coordinates : readVectors) {
//            std::cout << "x: " << coordinates.x << ", y: " << coordinates.y
//                      << ", x1: " << coordinates.x1 << ", y1: " << coordinates.y1 << std::endl;
//        }
    }

    else if (type == "segments") {
        data.generateSegments(numPoints, blurCoefficient, startPoint, endPoint);
                std::vector<Data::SegmentsCoordinates> readVectors = data.readSegmentsFromFile("segments.txt");
        for (const auto& coordinates : readVectors) {
            std::cout << "x: " << coordinates.x << ", y: " << coordinates.y
                      << ", x1: " << coordinates.x1 << ", y1: " << coordinates.y1 << std::endl;
        }

    }

    else if (type == "repeat_segments") {
        data.generateRepeatSegments(numPoints, blurCoefficient, startPoint, endPoint);
    }

    else if (type == "segment_with_dif_len") {
        if (argc < 10) {
            std::cerr << "Usage for segments_from_point: " << argv[0] << " <type> <numPoints> <blurCoefficient> <startX> <startY> <endX> <endY> <minLength> <maxLength>" << std::endl;
            return 1;
        }
        double minLength = std::stod(argv[8]);
        double maxLength = std::stod(argv[9]);
        data.generateSegmentsWithDidLen(numPoints, blurCoefficient, startPoint, endPoint, minLength, maxLength);
    }

    else {
        std::cerr << "Invalid generation type: " << type << std::endl;
        return 1;
    }
    return 0;
}

