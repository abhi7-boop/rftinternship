#include <bits/stdc++.h>
using namespace std;

string encryptPass(string pass){
    // Caesar shift + reverse
    for(char &c : pass) c += 1;
    reverse(pass.begin(), pass.end());
    return pass;
}

bool userExists(string username){
    ifstream file("users.txt");
    if(!file){
        cout<<"Error: File not found\n";
        return false;
    }

    string u,p;
    while(file>>u>>p){
        if(u==username) return true;
    }
    return false;
}

void registerUser(){
    string username,password;
    cout<<"Enter username: ";
    cin>>username;

    if(userExists(username)){
        cout<<"Username already exists!\n";
        return;
    }

    cout<<"Enter password: ";
    cin>>password;

    ofstream file("users.txt", ios::app);
    file<<username<<" "<<encryptPass(password)<<endl;

    cout<<"Registration successful!\n";
}

void loginUser(){
    ifstream file("users.txt");
    if(!file){
        cout<<"Error: File not found\n";
        return;
    }

    // check empty file
    file.seekg(0, ios::end);
    if(file.tellg()==0){
        cout<<"No users registered!\n";
        return;
    }
    file.seekg(0);

    string username,password;
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;

    string u,p;
    string enc = encryptPass(password);

    while(file>>u>>p){
        if(u==username && p==enc){
            cout<<"Login successful 🎉\n";
            return;
        }
    }

    cout<<"Wrong credentials!\n";
}

int main(){
    int choice;
    while(true){
        cout<<"\n1.Register\n2.Login\n3.Exit\nChoice: ";
        cin>>choice;

        if(choice==1) registerUser();
        else if(choice==2) loginUser();
        else if(choice==3) break;
        else cout<<"Invalid choice\n";
    }
}
