# ifndef FUNCTIONAL_HEADER
# define FUNCTIONAL_HEADER
# include<string>
# include<map>
# include<vector>

class Dictionary{
private:
    std::map<int,std::string> id2words;
    std::map<std::string,int> words2id;
public:
    Dictionary();
    ~Dictionary();
    void add(std::string word);
    void save(std::string filename);
    int operator[](std::string word);
    std::string operator[](int idx);
    void load(std::string filename);
    void clear();
};

class Dataset{
private:
    std::string root_dir;
    std::string data_name;
    std::string data_tag;
    Dictionary rel_dict,ent_dict;
    std::vector<std::vector<int> > all_data;
public:
    Dataset(std::string root_dir,std::string data_name,std::string data_tag);
    ~Dataset();
    void build();
};

class CKRLModel{

};
# endif
