# include<ctime>
# include<cstdlib>
# include<cstring>

# include<iostream>
# include<fstream>

# include "functional.hpp"

void prepare(std::string data_dir = "./data"){
    // load the dictionary
    std::ifstream ent_fp,rel_fp;
    std::string ent_filename = data_dir + "/data/entity2id.txt";
    auto ent_dict = Dictionary();
    ent_dict.load(ent_filename);
    std::string rel_filename = data_dir + "/data/relation2id.txt";
    auto rel_dict = Dictionary();
    rel_dict.load(rel_filename);

}

int ArgPos(std::string str, int argc,char **argv){
    for(int a=1;a<argc;a++){
        if(!strcmp(str.c_str(),argv[a])){
            if(a == argc -1){
                std::cout<<"Argument missing for "<<str<<std::endl;
                exit(1);
            }
            return a;
        }
    }
    return -1;
}

int main(int argc,char** argv){
    srand((unsigned)time(NULL));
    int method = 1;
    int size = 50;
    double learning_rate = 0.001;
    double margin = 1;
    std::string version;

    int k;
    if ((k=ArgPos((char*)"-size",argc,argv))>0) size = atoi(argv[k+1]);
    if ((k=ArgPos((char*)"-margin",argc,argv))>0) margin = atoi(argv[k+1]);
    if ((k=ArgPos((char*)"-method",argc,argv))>0) method = atoi(argv[k+1]);
    if ((k=ArgPos((char*)"-rate",argc,argv))>0) learning_rate = atof(argv[k+1]);
    
    std::cout<<"size = "<<size<<std::endl;
    std::cout<<"leanring rate = "<<learning_rate<<std::endl;
    std::cout<<"margin = "<<margin<<std::endl;
    if(method!=0){
        version = "bern";
    }else{
        version = "unif";
    }

    std::cout<<"method = "<<std::endl;
    prepare();
}

