# include "functional.hpp"
# include<fstream>
# include<iostream>

Dictionary::Dictionary(){

}

Dictionary::~Dictionary(){

}

void Dictionary::clear(){
    this->words2idx.clear();
    this->idx2words.clear();
}

int Dictionary::operator[](std::string word){
    return this->words2idx[word];
}

int Dictionary::getIdx(std::string word){
    return this->words2idx[word];
}

std::string Dictionary::getWord(int index){
    return this->idx2words[index];
}

unsigned int Dictionary::size(){
    return this->words2idx.size();
}
    
void Dictionary::load(std::string load_filename){
    std::ifstream file_fp;
    file_fp.open(load_filename,std::ios::in);
    while(!file_fp.eof()){
        std::string name;
        int index;
        file_fp>>name>>index;
        std::cout<<name<<"\t"<<index<<"\t"<<std::endl;
        this->words2idx.insert(std::make_pair(name,index));
        this->idx2words.insert(std::make_pair(index,name));
    }
    file_fp.close();
}
