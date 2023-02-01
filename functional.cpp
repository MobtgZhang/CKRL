# include "functional.hpp"
# include <cassert>
# include <iostream>
# include <fstream>
/*The Dictionary build*/

Dictionary::Dictionary(){
    id2words.insert(std::make_pair(0,"UNK"));
    words2id.insert(std::make_pair("UNK",0));
}
Dictionary::~Dictionary(){

}

int Dictionary::operator[](std::string word){
    auto iter = words2id.find(word);
    if(iter==words2id.end()) iter = words2id.find("UNK");
    return iter->second;
}

std::string Dictionary::operator[](int idx){
    auto iter = id2words.find(idx);
    if(iter==id2words.end()) iter = id2words.find(0);
    return iter->second;
}

void Dictionary::add(std::string word){
    auto iter = words2id.find(word);
    if(iter==words2id.end()){
        auto index = id2words.size();
        words2id.insert(std::make_pair(word,index));
        id2words.insert(std::make_pair(index,word));
    }
}

void Dictionary::save(std::string filename){
    std::ofstream ofs;
    ofs.open(filename,std::ios::out);
    for(auto iter=words2id.begin();iter!=words2id.end();iter++){
        ofs<<iter->first<<"\t"<<iter->second<<std::endl;
    }
    ofs.close();
}

void Dictionary::load(std::string filename){
    this->clear();
    std::ifstream ifs;
    ifs.open(filename,std::ios::in);
    int index;
    std::string word;
    while(!ifs.eof()){
        ifs>>word>>index;
        words2id.insert(std::make_pair(word,index));
        id2words.insert(std::make_pair(index,word));
    }
    ifs.close();
}

void Dictionary::clear(){
    words2id.clear();
    id2words.clear();
}



/*The Dataset build*/
Dataset::Dataset(std::string root_dir,std::string data_name,std::string data_tag){
    this->data_name = data_name;
    this->data_tag = data_tag;
    this->root_dir = root_dir;
    /*load dictionary*/
    //rel_dict.load(root_dir+"/"+data_name+"/"+"relations.txt");
    //ent_dict.load(root_dir+"/"+data_name+"/"+"entities.txt");
}
Dataset::~Dataset(){

}
void Dataset::build(){
    std::string load_filename = root_dir+"/"+data_name+"/"+data_tag+".txt";
    std::ifstream ifs;
    if(ifs.fail()){
        std::cout<<"open file "<<load_filename <<" error!"<<std::endl;
        exit(1);
    }
    std::string head_ent,relation,tail_ent;
    ifs.open(load_filename);
    std::cout<<load_filename<<std::endl;
    while(!ifs.eof()){
        ifs>>head_ent>>relation>>tail_ent;
        ent_dict.add(head_ent);
        ent_dict.add(tail_ent);
        rel_dict.add(relation);
        auto head = ent_dict[head_ent];
        auto tail = ent_dict[tail_ent];
        auto rel = rel_dict[relation];
        std::vector<int> tmp_v;tmp_v.push_back(head);tmp_v.push_back(rel);tmp_v.push_back(tail);
        this->all_data.push_back(tmp_v);
    }
    std::cout<<"The "<<data_tag<<" dataset number is "<<all_data.size()<<std::endl;
    ifs.close();
}

