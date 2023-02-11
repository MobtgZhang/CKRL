# ifndef FUNCTIONAL_H
# define FUNCTIONAL_H
# include<string>
# include<map>

class Dictionary{
private:
    std::map<std::string,int> words2idx;
    std::map<int,std::string> idx2words;
public:
    Dictionary();
    ~Dictionary();
    int operator[](std::string word);
    int getIdx(std::string word);
    std::string getWord(int index);
    unsigned int size();
    void load(std::string load_filename);
    void clear();
};

# endif
