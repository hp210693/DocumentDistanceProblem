#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_map>

class Document {
    public:
        Document(std::string path_document);
        ~Document();
        void GetWords(std::unordered_multimap<std::string, int>& map_word_list);
        std::string GetPathDocument() const;
    private:
        bool IsAscii(const std::string& word);
        void CountFrequency(std::string key_word, std::unordered_multimap<std::string, int>& map_word_list);
            
    private:
        std::string path_document_;
};