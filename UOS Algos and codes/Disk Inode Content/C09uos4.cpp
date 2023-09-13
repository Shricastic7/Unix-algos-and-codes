#include<iostream>
#include<sys/stat.h>
using namespace std;

int main()
{
char fname[255];
cout<<"Enter absolute path for your file:" ;            
cin>>fname;
struct stat var;                            
int ret=stat(fname,&var);                        

if(ret<0)
{
cout<<"System call stat exited with an error code" <<ret<<endl;
}
else
{
cout<< "Device id:"<<var.st_dev<<endl;
cout<<"Inode number:"<<var.st_ino<<endl;
cout<<"Mode:"<<var.st_mode<<endl;
cout<<"UID:"<<var.st_uid<<endl;
cout<<"GID:"<<var.st_gid<<endl;
cout<<"Size:"<<var.st_size<<endl;
}


struct stat
{
dev_t     st_dev;     
ino_t     st_ino;     
mode_t    st_mode;    
nlink_t   st_nlink;   
uid_t     st_uid;     
gid_t     st_gid;     
off_t     st_size;    
blksize_t st_blksize; 
blkcnt_t  st_blocks;  
};

}
