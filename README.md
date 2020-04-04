# Tested
    - OS: Suse linux
    - Compiler: GCC 9.2.1
    - IDE: Visual Studio Code

# Guideline to create shared library and executable file by cmake
    - mkdir build
    - cd build
    - cmake ..
    - make
    - ./ccdist path_to_first_doc path_to_second_doc

# Guideline to create shared library and executable file by manual
    - Shared library 
        + g++ -m64 -fPIC -c -std=c++17 document_distance/*.cc api/*.cc
        + g++ -m64 -shared -o libdocument_distance.so *.o
        + Create shared library success
    - Executable file
        + g++ -m64 -c main.cc
        + g++ -m64 -o ccdist main.o libdocument_distance.so
        + rm *.o
        + Create executable file success

# Check file x32 or x64 bit
    - objdump -f document.o | grep ^architecture
        + architecture: i386 => x32 bit
        + architecture: i386:x86-64 => x64 bit
    - file document.o
        + document.o: ELF 32-bit LSB relocatable, Intel 80386, version 1 (SYSV), not stripped => x32 bit
        + document.o: ELF 64-bit LSB relocatable, x86-64, version 1 (SYSV), not stripped => x64 bit

# Guideline for run
    - Must be opened Terminal (mandatory)
    - cd your_path/DocumentDistanceProblem/
    - sudo cp libdocument_distance.so /usr/lib/
    - sudo ldconfig
    - ./ccdist path_to_first_doc path_to_second_doc
    - Example: ./ccdist "data_test/test.txt" "data_test/test2.txt"

# The complexity (big O) of the algorithm
    - O(ComputeDistance) <=> O(GetWords) + O(ComputeInnerProduct) <=> O(n) + O(n) = O(n)

# Few ways of computing the distance between documents
    - Word2Vec
    - Levenshtein Distance
    - LSA
    - LDA
    - Pachinko Allocation
    - doc2vec
    - WordNet
    - Jaccard similarity
    - Word Mover’s Distance
    - GloVe: Global Vectors for Word Representation 

# Ref
    - https://www.researchgate.net/post/What_is_the_best_method_for_finding_document_similarity
    - https://medium.com/@stephenhky/word-movers-distance-as-a-linear-programming-problem-6b0c2658592e
    - https://courses.csail.mit.edu/6.006/fall10/lectures/lecture1.pdf
    - https://www.andrew.cmu.edu/course/15-121/labs/HW-4%20Document%20Distance/lab.html
    - https://medium.com/@rabin_gaire/models-of-computation-document-distance-7be4a9850067
    - https://www.filipekberg.se/2014/02/17/calculating-document-distance/
    - https://datascience.stackexchange.com/questions/678/what-are-some-standard-ways-of-computing-the-distance-between-documents
    - http://text2vec.org/similarity.html#jaccard_similarity
    - https://en.wikipedia.org/wiki/Time_complexity#Linear_time
    - https://cmry.github.io/notes/euclidean-v-cosine

