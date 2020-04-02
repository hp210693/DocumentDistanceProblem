# Tested
    - OS: Suse linux
    - Compiler: GCC 9.2.1
    - IDE: Visual Studio Code

# Guideline to create shared library and executable file by manual
    - Shared library 
        + g++ -fPIC -c -std=c++17 *.cc api/*.cc
        + g++ -shared -o libdist.so *.o
        + Create shared library success
    - Executable file
        + g++ -c main.cc
        + g++ -o ccdist main.o libdist.so
        + rm *.o
        + Create executable file success

# Guideline for run
    - Must be opened Terminal (mandatory)
    - cd your_path/DocumentDistanceProblem/
    - sudo mv libccdist.so /usr/lib/
    - sudo ldconfig
    - ./ccdist path_to_first_doc path_to_second_doc
    - Example: ./ccdist "datatest/test.txt" "datatest/test2.txt"

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

