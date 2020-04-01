#include "distance.h"

/**
 * @brief Construct a new Distance:: Distance object
 * 
 * @param path_document_first path of document first
 * @param path_document_second path of document second
 */
Distance::Distance(std::string path_document_first, std::string path_document_second):
                    path_document_first_ {path_document_first},
                    path_document_second_ {path_document_second} {
}

/**
 * @brief Destroy the Distance:: Distance object
 * 
 */
Distance::~Distance() {
}

/**
 * @brief Get path of document first
 * 
 * @return std::string Return path of document first
 */
std::string Distance::GetPathDocumentFirst() const {
    return path_document_first_;
}

/**
 * @brief Get path of document second
 * 
 * @return std::string Return path of document second
 */
std::string Distance::GetPathDocumentSecond() const {
    return path_document_second_;
}

/**
 * @brief The distance between two documents
 * 
 * @return double the angle between two document
 */
double Distance::ComputeDistance() {
    std::unordered_multimap<std::string, int> map_document_first;
    std::unordered_multimap<std::string, int> map_document_second;

    Document document_first(GetPathDocumentFirst());
    Document document_sencond(GetPathDocumentSecond());
    
    // Get words into each document
    document_first.GetWords(map_document_first);
    document_sencond.GetWords(map_document_second);

    int numerator = ComputeInnerProduct(map_document_first, map_document_second);

    int denominator = std::sqrt(ComputeInnerProduct(map_document_first, map_document_first) * ComputeInnerProduct(map_document_second, map_document_second));

    return std::acos(numerator / denominator);
}

/**
 * @brief 
 * 
 * @param map_document_first Contain a map of words have counted frequency
 * @param map_document_second Contain a map of words have counted frequency
 * @return int 
 */
int Distance::ComputeInnerProduct(std::unordered_multimap<std::string, int>& map_document_first, std::unordered_multimap<std::string, int>& map_document_second) {
    int sum = 0;
    for (auto [key, value] : map_document_first) {
        if (map_document_second.find(key) != map_document_second.end()) {
            sum += value * map_document_second.find(key)->second;
        }
    }

    return sum;
}

/**
 * @brief Public API ccdict for compute distance
 * 
 * @param path_document_first  path of document first
 * @param path_document_second  path of document second
 * @return double 
 */
double ccdist(std::string path_document_first, std::string path_document_second) {
    Distance dis = {path_document_first, path_document_second};
    return dis.ComputeDistance();
}