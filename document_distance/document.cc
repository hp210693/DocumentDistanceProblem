#include "document.h"
/**
 * @brief Construct a new Document:: Document object
 * 
 * @param path_document Path of a document
 */
Document::Document(std::string path_document): path_document_ {path_document} {

}

/**
 * @brief Destroy the Document:: Document object
 * 
 */
Document::~Document() {

}

/**
 * @brief Get words in document and count frequency
 * 
 * @param map_word_list Contain a map of words have counted frequency
 */
void Document::GetWords(std::unordered_multimap<std::string, int>& map_word_list) {
    std::ifstream document;
    // Open a document
    document.open(GetPathDocument(), std::ofstream::in);

    if (document.is_open()) { // Check the document is opened
        std::string word;
        // Read each line and get each word
        while (document >> word) {
            // Convert a word to lowercase letters
            std::transform(word.begin(), word.end(), word.begin(),
                            [] (unsigned char character) -> unsigned char { return std::tolower(character);});
                            
            if (IsAscii(word)) { // Check a word is ASCII character
                CountFrequency(word, map_word_list);
            }
        }
    } else {
        // The document is not opened
        std::cout << "Unable open the document\n";
    }
    
    // Closed a document
    document.close();
}

/**
 * @brief To get path of document
 * 
 * @return std::string Return path of a document
 */
std::string Document::GetPathDocument() const {
    return path_document_;
}

/**
 * @brief Count frequency of each characters
 * 
 * @param key_word A word in document
 * @param map_word_list Contain a map of words have counted frequency
 */
void Document::CountFrequency(std::string key_word, std::unordered_multimap<std::string, int>& map_word_list) {
    // Finding key_word already exist
    if (map_word_list.find(key_word) != map_word_list.end()) {
       ++map_word_list.find(key_word)->second; // Increase the value of the key_word to 1 value
    } else {
        // The key_word is not exist
        map_word_list.insert({key_word, 1}); // Insert new key_word with value equal 1 into map_word_list       
    }
}

/**
 * @brief Check all word is ASCII characters
 * 
 * @param word A word in document
 * @return true If only word has ASCII characters
 * @return false If least word has non ASCII characters
 */
bool Document::IsAscii(const std::string& word) {
    // A character lager 127 is not ANSII character
    return !std::any_of(word.begin(), word.end(),
                        [] (char c) {return static_cast<unsigned char>(c) > 127;});
}