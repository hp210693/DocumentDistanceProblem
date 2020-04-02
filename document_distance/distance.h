#include <iostream>
#include <unordered_map>
#include <cmath>
#include "document.h"

class Distance {
    public:
        Distance(std::string path_document_first, std::string path_document_second);
        ~Distance();
        double ComputeDistance();
    private:
        std::string GetPathDocumentFirst() const;
        std::string GetPathDocumentSecond() const;
        int ComputeInnerProduct(std::unordered_multimap<std::string, int>& map_document_first, std::unordered_multimap<std::string, int>& map_document_second);

    private:
        std::string path_document_first_;
        std::string path_document_second_;
};
