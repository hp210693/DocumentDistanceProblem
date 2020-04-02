#include "../distance.h"
#include "distance_api.h"
#include <string>

/**
 * @brief Public API ccdict for compute distance
 * 
 * @param path_document_first  path of document first
 * @param path_document_second  path of document second
 * @return double the angle between two document
 */
double ccdist(std::string path_document_first, std::string path_document_second) {
    Distance dis = {path_document_first, path_document_second};
    return dis.ComputeDistance();
}