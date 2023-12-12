#pragma once
#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <iomanip>

/**
 * @brief Class Data for generating and processing coordinate data.
 */
class Data {
public:
    /**
     * @brief Structure representing a point in two-dimensional space.
     */
    struct Point {
        double x; /**< X-coordinate */
        double y; /**< Y-coordinate */
    };

    /**
     * @brief Structure representing the coordinates of linear segments in two-dimensional space.
     */
    struct SegmentsCoordinates {
        double x, y, x1, y1; /**< Initial and final coordinates of the linear segment */
    };

    /**
     * @brief Constructor of the Data class.
     */
    Data();

    /**
     * @brief Writes the coordinates of linear segments to a file.
     * @param coordinates Vector of Point representing linear segments.
     * @param filename Output file name.
     */
    void writeSegmentsToFile(const std::vector<Point>& coordinates, const std::string& filename);

    /**
     * @brief Writes individual points to a file.
     * @param coordinates Vector of Point representing individual points.
     * @param filename Output file name.
     */
    void writePointsToFile(const std::vector<Point>& coordinates, const std::string& filename);

    /**
     * @brief Generates linear segments starting from a specified point.
     * @param numSegments Number of generated linear segments.
     * @param noiseStd Standard deviation of Gaussian noise for coordinates.
     * @param start Starting point of the segments.
     * @param end Ending point of the segments.
     */
    void generateSegmentsFromPoint(int numSegments, double noiseStd, const Point& start, const Point& end);

    /**
     * @brief Generates linear segments between two points.
     * @param numPoints Number of generated points.
     * @param noiseStd Standard deviation of Gaussian noise for coordinates.
     * @param start Starting point of the segments.
     * @param end Ending point of the segments.
     */
    void generateSegments(int numPoints, double noiseStd, const Point& start, const Point& end);

    /**
     * @brief Generates linear segments with specified length constraints.
     * @param numSegments Number of generated linear segments.
     * @param noiseStd Standard deviation of Gaussian noise for coordinates.
     * @param start Starting point of the segments.
     * @param end Ending point of the segments.
     * @param minLength Minimum length of the segments.
     * @param maxLength Maximum length of the segments.
     */
    void generateSegmentsWithDidLen(int numSegments, double noiseStd, const Point& start, const Point& end, double minLength, double maxLength);

    /**
     * @brief Generates repeating linear segments.
     * @param numSegments Number of generated linear segments.
     * @param noiseStd Standard deviation of Gaussian noise for coordinates.
     * @param start Starting point of the segments.
     * @param end Ending point of the segments.
     */
    void generateRepeatSegments(int numSegments, double noiseStd, const Point& start, const Point& end);

    /**
     * @brief Reads points from a file.
     * @param filename Input file name.
     * @return Vector of SegmentsCoordinates representing points.
     */
    std::vector<SegmentsCoordinates> readPointsFromFile(const char* filename);

    /**
     * @brief Reads linear segments from a file.
     * @param filename Input file name.
     * @return Vector of SegmentsCoordinates representing linear segments.
     */
    std::vector<SegmentsCoordinates> readSegmentsFromFile(const char* filename);

private:
    std::default_random_engine generator; /**< Random number generator */
    std::normal_distribution<double> distribution; /**< Normal distribution for Gaussian noise */
    std::uniform_real_distribution<double> lengthDistribution; /**< Uniform distribution for segment length */
};

#endif // DATA_HPP


