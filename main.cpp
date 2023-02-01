# include<cstdlib>
# include<ctime>
# include<cstring>
# include<iostream>
int ArgPos(char*str, int argc,char**argv){
    for(int a=1;a<argc;a++){
        if(!strcmp(str,argv[a])){
            if (a==argc -1){
                std::cout<<"Argument missing for "<<str<<std::endl;
                exit(1);
            }
        }
        return a;
    }
    return -1;
}

int main(int argc,char**argv){
    srand((unsigned)time(NULL));
    int method = 1;
    int n = 50;     //dimention
    double learning_rate = 0.001;    //learning_rate
    double margin = 1;      //loss margin
    int arg_idx ;
    std::string version;
    if ((arg_idx =ArgPos((char*)"-size",argc,argv))>0) n = atoi(argv[arg_idx+1]);
    if ((arg_idx =ArgPos((char*)"-margin",argc,argv))>0) margin = atoi(argv[arg_idx+1]);
    if ((arg_idx =ArgPos((char*)"-method",argc,argv))>0) method = atoi(argv[arg_idx+1]);
    std::cout<<"size = "<<n<<std::endl;
    std::cout<<"learning rate = "<<learning_rate<<std::endl;
    std::cout<<"margin = "<<margin<<std::endl;
    if(method){
        version = "bern";
    }else{
        version = "unif";
    }
    std::cout<<"method = "<<version<<std::endl;
}