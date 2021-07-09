#include<bits/stdc++.h>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<math.h>
#include<conio.h>
using namespace std;

//Chess Game//

void getposition(vector<string> &game,int row){
    for(int i=0;i<row;i++){
        string s;
        getline(cin,s);
        game.push_back(s);
    }
}

void viewposition(vector<string> game){
    cout<<"The given position is as follows: "<<endl;
    for(int i=0;i<game.size();i++){
        cout<<game[i]<<endl;
    }
}

bool checkvalid(vector<string> &game,unordered_set<string> &hash_char){
    string checking="";
    for(int i=0;i<game.size();i++){
        for(int j=0;j<game[i].length();j++){
            if(game[i].length()<=20){
                cout<<"There are less than 64 squares on the board"<<endl;
                return false;
            }
            if(game[i].length()>23){
                cout<<"There are more than 64 squares on the board"<<endl;
                return false;
            }
            if(game[i][j]==' '||j==game[i].length()-1){
                if(j==game[i].length()-1){
                    checking+=game[i][j];
                }
                if(hash_char.find(checking)==hash_char.end()){
                    cout<<checking<<endl;
                    cout<<"The above mentioned string is not one of the given strings"<<endl;
                    return false;
                }
                checking="";
            }
            if(game[i][j]!=' '&&j!=game[i].length()-1){
                checking+=game[i][j];
            }
        }
    }
    return true;
}

void createhash(unordered_set<string> &hash_char){
    hash_char.insert("WP");
    hash_char.insert("WR");
    hash_char.insert("WN");
    hash_char.insert("WB");
    hash_char.insert("WQ");
    hash_char.insert("WK");
    hash_char.insert("11");
    hash_char.insert("BP");
    hash_char.insert("BR");
    hash_char.insert("BN");
    hash_char.insert("BB");
    hash_char.insert("BQ");
    hash_char.insert("BK");
    return;
}

void showrules(){
    cout<<"Enter the game position according to the rules below: "<<endl;
    cout<<"Enter the strings given below"<<endl;
    cout<<"WP for White Pawn"<<endl;
    cout<<"WR for White Rook"<<endl;
    cout<<"WN for White Knight"<<endl;
    cout<<"WB for White Bishop"<<endl;
    cout<<"WQ for White Queen"<<endl;
    cout<<"WK for White King"<<endl;
    cout<<"BP for Black Pawn"<<endl;
    cout<<"BR for Black Rook"<<endl;
    cout<<"BN for Black Knight"<<endl;
    cout<<"BB for Black Bishop"<<endl;
    cout<<"BQ for Black Queen"<<endl;
    cout<<"BK for Black King"<<endl;
    cout<<"11 for Empty Space"<<endl;
    cout<<"Enter a space after each string and please do not enter multiple spaces "<<endl;
}
int piececounting(vector<string> &game,string piece){
    string checking="";
    int count=0;
    for(int i=0;i<game.size();i++){
        for(int j=0;j<game[i].length();j++){
             if(game[i][j]==' '||j==game[i].length()-1){
                if(j==game[i].length()-1){
                    checking+=game[i][j];
                }
                if(checking==piece){
                    count++;
                }
                checking="";
            }
            if(game[i][j]!=' '&&j!=game[i].length()-1){
                checking+=game[i][j];
            }
        }
    }
    return count;
}

vector<int> findpiece(vector<string> &game,string piece){
    vector<int> ans;
    for(int i=0;i<game.size();i++){
        if(game[i].find(piece)!=string::npos){
            ans.push_back(i);
            ans.push_back(game[i].find(piece));
        }
    }
    return ans;
}

bool pawnsonnthrank(vector<string> &game,string piece,int row){
    if(game[row].find(piece)!=string::npos){
        return true;
    }
    return false;
}

void showopeningposition(){
    cout<<"The starting position of the chess game is as given below "<<endl;
    cout<<"BR BN BB BQ BK BB BN BR"<<endl;
    cout<<"BP BP BP BP BP BP BP BP"<<endl;
    cout<<"11 11 11 11 11 11 11 11"<<endl;
    cout<<"11 11 11 11 11 11 11 11"<<endl;
    cout<<"11 11 11 11 11 11 11 11"<<endl;
    cout<<"11 11 11 11 11 11 11 11"<<endl;
    cout<<"WP WP WP WP WP WP WP WP"<<endl;
    cout<<"WR WN WB WQ WK WB WN WR"<<endl;
}

bool checkformultiplespaces(vector<string> &game){
    for(int i=0;i<game.size();i++){
        for(int j=0;j<game[i].length();j++){
            if(game[i][j]==' '&&game[i][j+1]==' '){
                return true;
            }
        }
    }
    return false;
}

int piececountingonrank(vector<string> &game,string piece,int rank){
    int count=0;
    string checking="";
    for(int j=0;j<game[rank].length();j++){
        if(game[rank][j]==' '||j==game[rank].length()-1){
            if(j==game[rank].length()-1){
                checking+=game[rank][j];
            }
            if(checking==piece){
                count++;
            }
            checking="";
        }
        if(game[rank][j]!=' '&&j!=game[rank].length()-1){
            checking+=game[rank][j];
        }
    }
    return count;
}

void checkpieces(vector<string> &game,unordered_set<string> hash_char){
    vector<int> positionofblackking;
    vector<int> positionofwhiteking;
    vector<int> positionofblackqueen;
    vector<int> positionofwhitequeen;
    vector<int> positionofblackrooks;
    vector<int> positionofwhiterooks;
    vector<int> positionofblackbishops;
    vector<int> positionofwhitebishops;
    int numberofblackpawns=piececounting(game,"BP"),numberofwhitepawns=piececounting(game,"WP"),flag=0;
    int possibleextrablackpieces=8-piececounting(game,"BP");
    int possibleextrawhitepieces=8-piececounting(game,"WP");
    int countofwhitepawnsonrank2=piececountingonrank(game,"WP",6);
    int countofblackpawnsonrank7=piececountingonrank(game,"BP",1);
    if(checkvalid(game,hash_char)==true){
        int blackkings=piececounting(game,"BK");
        if(blackkings<1){
            cout<<"There is no black king in the game"<<endl;
            cout<<"Hence this is an invlaid position"<<endl;
            return;
        }
        else if(blackkings>1){
            cout<<"There is more than one black king in the game"<<endl;
            cout<<"Hence this is an invalid postiion"<<endl;
            return;
        }
        else{
            positionofblackking=findpiece(game,"BK");
        }
        int whitekings=piececounting(game,"WK");
        if(whitekings<1){
            cout<<"There is no white king in the game"<<endl;
            cout<<"Hence this is an invalid position"<<endl;
            return;
        }
        else if(whitekings>1){
            cout<<"There is more than one white king in the game"<<endl;
            cout<<"Hence this is an invalid postiion"<<endl;
            return;
        }
        else{
            positionofwhiteking=findpiece(game,"WK");
            if(abs(positionofwhiteking[0]-positionofblackking[0])<=1&&abs(positionofwhiteking[1]-positionofblackking[1])<=3){
                cout<<"The Kings are next to each other"<<endl;
                cout<<"Hence this is an invalid position"<<endl;
                return;
            }
        }
        if(countofblackpawnsonrank7==8){
            if(positionofblackking[0]>0){
                cout<<"The black king cannot jump over the black pawns"<<endl;
                cout<<"Hence, this is an invalid position"<<endl;
                return;
            }
        }
        if(countofwhitepawnsonrank2==8){
            if(positionofwhiteking[0]<7){
                cout<<"The white king cannot jump over the white pawns"<<endl;
                cout<<"Hence, this is an invalid position"<<endl;
                return;
            }
        }
        if(pawnsonnthrank(game,"BP",0)==true){
            cout<<"The black pawn is on the last rank"<<endl;
            cout<<"Hence, this is an invalid position"<<endl;
            return;
        }
        if(pawnsonnthrank(game,"WP",7)==true){
            cout<<"The White Pawn is on the first rank"<<endl;
            cout<<"Hence, this is an invalid position"<<endl;
            return;
        }
        if(numberofblackpawns>8){
            cout<<"There are more than 8 black pawns"<<endl;
            cout<<"Hence this is an invalid position"<<endl;
            return;
        }
        if(numberofwhitepawns>8){
            cout<<"There are more than 8 white pawns"<<endl;
            cout<<"Hence this is an invalid position"<<endl;
            return;
        }
        if(piececounting(game,"BQ")-1>possibleextrablackpieces){
            cout<<"The possible number of black queens is more than possible number of black pieces"<<endl;
            cout<<"Hence, this is an invalid position"<<endl;
            return;
        }
        else{
            possibleextrablackpieces-=piececounting(game,"BQ")-1;
        }
        if(piececounting(game,"WQ")-1>possibleextrawhitepieces){
            cout<<"The possible number of white queens is more than possible number of white pieces"<<endl;
            cout<<"Hence, this is an invalid position"<<endl;
            return;
        }
        else{
            possibleextrawhitepieces-=piececounting(game,"WQ")-1;
        }
        if(countofblackpawnsonrank7==8){
            positionofblackqueen=findpiece(game,"BQ");
            if(positionofblackqueen[0]>0){
                cout<<"The black queen cannot jump over the black pawns"<<endl;
                cout<<"Hence, this is an invalid position"<<endl;
                return;
            }
        }
        if(countofwhitepawnsonrank2==8){
            positionofwhitequeen=findpiece(game,"WQ");
            if(positionofwhitequeen[0]<7){
                cout<<"The white queen cannot jump over the white pawns"<<endl;
                cout<<"Hence, this is an invalid position"<<endl;
                return;
            }
        }
        if(piececounting(game,"BR")-2>possibleextrablackpieces){
            cout<<"The possible number of black rooks is more than possible number of black pieces"<<endl;
            cout<<"Hence, this is an invalid position"<<endl;
            return;
        }
        else{
            possibleextrablackpieces-=piececounting(game,"BR")-2;
        }
        if(piececounting(game,"WR")-2>possibleextrawhitepieces){
            cout<<"The possible number of white rooks is more than possible number of white pieces"<<endl;
            cout<<"Hence, this is an invalid position"<<endl;
            return;
        }
        else{
            possibleextrawhitepieces-=piececounting(game,"WR")-2;
        }
        positionofblackrooks=findpiece(game,"BR");
        if(countofblackpawnsonrank7==8){
            for(int i=0;i<positionofblackrooks.size();i=i+2){
                if(positionofblackrooks[i]>0){
                    cout<<"The black rooks cannot jump over the black pawns"<<endl;
                    cout<<"Hence, this is an invalid position"<<endl;
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                return;
            }
        }
        positionofwhiterooks=findpiece(game,"WR");
        if(countofwhitepawnsonrank2==8){
            for(int i=0;i<positionofwhiterooks.size();i=i+2){
                if(positionofwhiterooks[i]<7){
                    cout<<"The white rooks cannot jump over the white pawns"<<endl;
                    cout<<"Hence, this is an invalid position"<<endl;
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                return;
            }
        }
        if(piececounting(game,"BB")-2>possibleextrablackpieces){
            cout<<"The possible number of black bishops is more than possible number of black pieces"<<endl;
            cout<<"Hence, this is an invalid position"<<endl;
            return;
        }
        else{
            possibleextrablackpieces-=piececounting(game,"BB")-2;
        }
        if(piececounting(game,"WB")-2>possibleextrawhitepieces){
            cout<<"The possible number of white bishops is more than possible number of white pieces"<<endl;
            cout<<"Hence, this is an invalid position"<<endl;
            return;
        }
        else{
            possibleextrawhitepieces-=piececounting(game,"WB")-2;
        }
        positionofblackbishops=findpiece(game,"BB");
        if(countofblackpawnsonrank7==8){
            for(int i=0;i<positionofblackbishops.size();i=i+2){
                if(positionofblackbishops[i]>0){
                    cout<<"The black bishops cannot jump over the black pawns"<<endl;
                    cout<<"Hence, this is an invalid position"<<endl;
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                return;
            }
        }
        positionofwhitebishops=findpiece(game,"WB");
        if(countofwhitepawnsonrank2==8){
            for(int i=0;i<positionofwhitebishops.size();i=i+2){
                if(positionofwhitebishops[i]<7){
                    cout<<"The white bishops cannot jump over the white pawns"<<endl;
                    cout<<"Hence, this is an invalid position"<<endl;
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                return;
            }
        }
        if(piececounting(game,"BN")-2>possibleextrablackpieces){
            cout<<"The possible number of black knights is more than possible number of black pieces"<<endl;
            cout<<"Hence, this is an invalid position"<<endl;
            return;
        }
        else{
            possibleextrablackpieces-=piececounting(game,"BN")-2;
        }
        if(piececounting(game,"WN")-2>possibleextrawhitepieces){
            cout<<"The possible number of white knights is more than possible number of white pieces"<<endl;
            cout<<"Hence, this is an invalid position"<<endl;
            return;
        }
        else{
            possibleextrawhitepieces-=piececounting(game,"WN")-2;
        }
        cout<<"This is a valid game position"<<endl;
    }
}

bool checkforsiciliandefense(vector<string> &game){
    vector<string> siliciandefense;
    siliciandefense.push_back("BR BN BB BQ BK BB BN BR");
    siliciandefense.push_back("BP BP 11 BP BP BP BP BP");
    siliciandefense.push_back("11 11 11 11 11 11 11 11");
    siliciandefense.push_back("11 11 BP 11 11 11 11 11");
    siliciandefense.push_back("11 11 11 11 WP 11 11 11");
    siliciandefense.push_back("11 11 11 11 11 11 11 11");
    siliciandefense.push_back("WP WP WP WP 11 WP WP WP");
    siliciandefense.push_back("WR WN WB WQ WK WB WN WR");
    for(int i=0;i<game.size();i++){
        if(game[i]!=siliciandefense[i]){
            return false;
        }
    }
    return true;
}

bool checkforfrenchdefense(vector<string> &game){
    vector<string> frenchdefense;
    frenchdefense.push_back("BR BN BB BQ BK BB BN BR");
    frenchdefense.push_back("BP BP BP BP 11 BP BP BP");
    frenchdefense.push_back("11 11 11 11 BP 11 11 11");
    frenchdefense.push_back("11 11 11 11 11 11 11 11");
    frenchdefense.push_back("11 11 11 11 WP 11 11 11");
    frenchdefense.push_back("11 11 11 11 11 11 11 11");
    frenchdefense.push_back("WP WP WP WP 11 WP WP WP");
    frenchdefense.push_back("WR WN WB WQ WK WB WN WR");
    for(int i=0;i<game.size();i++){
        if(game[i]!=frenchdefense[i]){
            return false;
        }
    }
    return true;
}

bool checkforruylopez(vector<string> &game){
    vector<string> ruylopez;
    ruylopez.push_back("BR 11 BB BQ BK BB BN BR");
    ruylopez.push_back("BP BP BP BP 11 BP BP BP");
    ruylopez.push_back("11 11 BN 11 11 11 11 11");
    ruylopez.push_back("11 WB 11 11 BP 11 11 11");
    ruylopez.push_back("11 11 11 11 WP 11 11 11");
    ruylopez.push_back("11 11 11 11 11 WN 11 11");
    ruylopez.push_back("WP WP WP WP 11 WP WP WP");
    ruylopez.push_back("WR WN WB WQ WK 11 11 WR");
    for(int i=0;i<game.size();i++){
        if(game[i]!=ruylopez[i]){
            return false;
        }
    }
    return true;
}

bool checkforcarokann(vector<string> &game){
    vector<string> carokann;
    carokann.push_back("BR BN BB BQ BK BB BN BR");
    carokann.push_back("BP BP 11 BP BP BP BP BP");
    carokann.push_back("11 11 BP 11 11 11 11 11");
    carokann.push_back("11 11 11 11 11 11 11 11");
    carokann.push_back("11 11 11 11 WP 11 11 11");
    carokann.push_back("11 11 11 11 11 11 11 11");
    carokann.push_back("WP WP WP WP 11 WP WP WP");
    carokann.push_back("WR WN WB WQ WK WB WN WR");
    for(int i=0;i<game.size();i++){
        if(game[i]!=carokann[i]){
            return false;
        }
    }
    return true;
}

bool checkforitalian(vector<string> &game){
    vector<string> italian;
    italian.push_back("BR 11 BB BQ BK BB BN BR");
    italian.push_back("BP BP BP BP 11 BP BP BP");
    italian.push_back("11 11 BN 11 11 11 11 11");
    italian.push_back("11 11 11 11 BP 11 11 11");
    italian.push_back("11 11 WB 11 WP 11 11 11");
    italian.push_back("11 11 11 11 11 WN 11 11");
    italian.push_back("WP WP WP WP 11 WP WP WP");
    italian.push_back("WR WN WB WQ WK 11 11 WR");
    for(int i=0;i<game.size();i++){
        if(game[i]!=italian[i]){
            return false;
        }
    }
    return true;
}

bool checkforscandinavian(vector<string> &game){
    vector<string> scandinavian;
    scandinavian.push_back("BR BN BB BQ BK BB BN BR");
    scandinavian.push_back("BP BP BP 11 BP BP BP BP");
    scandinavian.push_back("11 11 11 11 11 11 11 11");
    scandinavian.push_back("11 11 11 BP 11 11 11 11");
    scandinavian.push_back("11 11 11 11 WP 11 11 11");
    scandinavian.push_back("11 11 11 11 11 11 11 11");
    scandinavian.push_back("WP WP WP WP 11 WP WP WP");
    scandinavian.push_back("WR WN WB WQ WK WB WN WR");
    for(int i=0;i<game.size();i++){
        if(game[i]!=scandinavian[i]){
            return false;
        }
    }
    return true;
}

bool checkforpircdefense(vector<string> &game){
    vector<string> pircdefense;
    pircdefense.push_back("BR BN BB BQ BK BB 11 BR");
    pircdefense.push_back("BP BP BP 11 BP BP BP BP");
    pircdefense.push_back("11 11 11 BP 11 BN 11 11");
    pircdefense.push_back("11 11 11 11 11 11 11 11");
    pircdefense.push_back("11 11 11 WP WP 11 11 11");
    pircdefense.push_back("11 11 11 11 11 11 11 11");
    pircdefense.push_back("WP WP WP 11 11 WP WP WP");
    pircdefense.push_back("WR WN WB WQ WK WB WN WR");
    for(int i=0;i<game.size();i++){
        if(game[i]!=pircdefense[i]){
            return false;
        }
    }
    return true;
}

bool checkforalekhinedefense(vector<string> &game){
    vector<string> alekhinedefense;
    alekhinedefense.push_back("BR BN BB BQ BK BB 11 BR");
    alekhinedefense.push_back("BP BP BP BP BP BP BP BP");
    alekhinedefense.push_back("11 11 11 11 11 BN 11 11");
    alekhinedefense.push_back("11 11 11 11 11 11 11 11");
    alekhinedefense.push_back("11 11 11 11 WP 11 11 11");
    alekhinedefense.push_back("11 11 11 11 11 11 11 11");
    alekhinedefense.push_back("WP WP WP WP 11 WP WP WP");
    alekhinedefense.push_back("WR WN WB WQ WK WB WN WR");
    for(int i=0;i<game.size();i++){
        if(game[i]!=alekhinedefense[i]){
            return false;
        }
    }
    return true;
}

bool checkforkingsgambit(vector<string> &game){
    vector<string> kingsgambit;
    kingsgambit.push_back("BR BN BB BQ BK BB BN BR");
    kingsgambit.push_back("BP BP BP BP 11 BP BP BP");
    kingsgambit.push_back("11 11 11 11 11 11 11 11");
    kingsgambit.push_back("11 11 11 11 BP 11 11 11");
    kingsgambit.push_back("11 11 11 11 WP WP 11 11");
    kingsgambit.push_back("11 11 11 11 11 11 11 11");
    kingsgambit.push_back("WP WP WP WP 11 11 WP WP");
    kingsgambit.push_back("WR WN WB WQ WK WB WN WR");
    for(int i=0;i<game.size();i++){
        if(game[i]!=kingsgambit[i]){
            return false;
        }
    }
    return true;
}

bool checkforscotchgame(vector<string> &game){
    vector<string> scotchgame;
    scotchgame.push_back("BR 11 BB BQ BK BB BN BR");
    scotchgame.push_back("BP BP BP BP 11 BP BP BP");
    scotchgame.push_back("11 11 BN 11 11 11 11 11");
    scotchgame.push_back("11 11 11 11 BP 11 11 11");
    scotchgame.push_back("11 11 11 WP WP 11 11 11");
    scotchgame.push_back("11 11 11 11 11 WN 11 11");
    scotchgame.push_back("WP WP WP 11 11 WP WP WP");
    scotchgame.push_back("WR WN WB WQ WK WB 11 WR");
    for(int i=0;i<game.size();i++){
        if(game[i]!=scotchgame[i]){
            return false;
        }
    }
    return true;
}

bool checkforvienna(vector<string> &game){
    vector<string> vienna;
    vienna.push_back("BR BN BB BQ BK BB BN BR");
    vienna.push_back("BP BP BP BP 11 BP BP BP");
    vienna.push_back("11 11 11 11 11 11 11 11");
    vienna.push_back("11 11 11 11 BP 11 11 11");
    vienna.push_back("11 11 11 11 WP 11 11 11");
    vienna.push_back("11 11 WN 11 11 11 11 11");
    vienna.push_back("WP WP WP WP 11 WP WP WP");
    vienna.push_back("WR 11 WB WQ WK WB WN WR");
    for(int i=0;i<game.size();i++){
        if(game[i]!=vienna[i]){
            return false;
        }
    }
    return true;
}

bool checkforqueensgambit(vector<string> &game){
    vector<string> queensgambit;
    queensgambit.push_back("BR BN BB BQ BK BB BN BR");
    queensgambit.push_back("BP BP BP BP 11 BP BP BP");
    queensgambit.push_back("11 11 11 11 11 11 11 11");
    queensgambit.push_back("11 11 11 11 BP 11 11 11");
    queensgambit.push_back("11 11 11 WP WP 11 11 11");
    queensgambit.push_back("11 11 11 11 11 11 11 11");
    queensgambit.push_back("WP WP WP 11 11 WP WP WP");
    queensgambit.push_back("WR WN WB WQ WK WB WN WR");
    for(int i=0;i<game.size();i++){
        if(game[i]!=queensgambit[i]){
            return false;
        }
    }
    return true;
}

bool checkforkingsindiandefense(vector<string> &game){
    vector<string> kingsindian;
    kingsindian.push_back("BR BN BB BQ BK BB 11 BR");
    kingsindian.push_back("BP BP BP BP BP BP 11 BP");
    kingsindian.push_back("11 11 11 11 11 BN BP 11");
    kingsindian.push_back("11 11 11 11 11 11 11 11");
    kingsindian.push_back("11 11 WP WP 11 11 11 11");
    kingsindian.push_back("11 11 11 11 11 11 11 11");
    kingsindian.push_back("WP WP 11 11 WP WP WP WP");
    kingsindian.push_back("WR WN WB WQ WK WB WN WR");
    for(int i=0;i<game.size();i++){
        if(game[i]!=kingsindian[i]){
            return false;
        }
    }
    return true;
}

bool checkfornimzoindian(vector<string> &game){
    vector<string> nimzoindian;
    nimzoindian.push_back("BR BN BB BQ BK 11 11 BR");
    nimzoindian.push_back("BP BP BP BP 11 BP BP BP");
    nimzoindian.push_back("11 11 11 11 BP BN 11 11");
    nimzoindian.push_back("11 11 11 11 11 11 11 11");
    nimzoindian.push_back("11 BB WP WP 11 11 11 11");
    nimzoindian.push_back("11 11 WN 11 11 11 11 11");
    nimzoindian.push_back("WP WP 11 11 WP WP WP WP");
    nimzoindian.push_back("WR 11 WB WQ WK WB WN WR");
    for(int i=0;i<game.size();i++){
        if(game[i]!=nimzoindian[i]){
            return false;
        }
    }
    return true;
}

bool checkforqueensindian(vector<string> &game){
    vector<string> queensindian;
    queensindian.push_back("BR BN BB BQ BK BB 11 BR");
    queensindian.push_back("BP 11 BP BP 11 BP BP BP");
    queensindian.push_back("11 BP 11 11 BP BN 11 11");
    queensindian.push_back("11 11 11 11 11 11 11 11");
    queensindian.push_back("11 11 WP WP 11 11 11 11");
    queensindian.push_back("11 11 11 11 11 WN 11 11");
    queensindian.push_back("WP WP 11 11 WP WP WP WP");
    queensindian.push_back("WR WN WB WQ WK WB 11 WR");
    for(int i=0;i<game.size();i++){
        if(game[i]!=queensindian[i]){
            return false;
        }
    }
    return true;
}

bool checkforbogoindian(vector<string> &game){
    vector<string> bogoindian;
    bogoindian.push_back("BR BN BB BQ BK 11 11 BR");
    bogoindian.push_back("BP BP BP BP 11 BP BP BP");
    bogoindian.push_back("11 11 11 11 BP BN 11 11");
    bogoindian.push_back("11 11 11 11 11 11 11 11");
    bogoindian.push_back("11 BB WP WP 11 11 11 11");
    bogoindian.push_back("11 11 11 11 11 WN 11 11");
    bogoindian.push_back("WP WP 11 11 WP WP WP WP");
    bogoindian.push_back("WR WN WB WQ WK WB 11 WR");
    for(int i=0;i<game.size();i++){
        if(game[i]!=bogoindian[i]){
            return false;
        }
    }
    return true;
}

bool checkfordutchdefense(vector<string> &game){
    vector<string> dutchdefense;
    dutchdefense.push_back("BR BN BB BQ BK BB BN BR");
    dutchdefense.push_back("BP BP BP BP BP 11 BP BP");
    dutchdefense.push_back("11 11 11 11 11 11 11 11");
    dutchdefense.push_back("11 11 11 11 11 BP 11 11");
    dutchdefense.push_back("11 11 11 WP 11 11 11 11");
    dutchdefense.push_back("11 11 11 11 11 11 11 11");
    dutchdefense.push_back("WP WP WP 11 WP WP WP WP");
    dutchdefense.push_back("WR WN WB WQ WK WB WN WR");
    for(int i=0;i<game.size();i++){
        if(game[i]!=dutchdefense[i]){
            return false;
        }
    }
    return true;
}

bool checkfortrompowskyattack(vector<string> &game){
    vector<string> trompowskyattack;
    trompowskyattack.push_back("BR BN BB BQ BK BB 11 BR");
    trompowskyattack.push_back("BP BP BP BP BP BP BP BP");
    trompowskyattack.push_back("11 11 11 11 11 BN 11 11");
    trompowskyattack.push_back("11 11 11 11 11 11 WB 11");
    trompowskyattack.push_back("11 11 11 WP 11 11 11 11");
    trompowskyattack.push_back("11 11 11 11 11 11 11 11");
    trompowskyattack.push_back("WP WP WP 11 WP WP WP WP");
    trompowskyattack.push_back("WR WN 11 WQ WK WB WN WR");
    for(int i=0;i<game.size();i++){
        if(game[i]!=trompowskyattack[i]){
            return false;
        }
    }
    return true;
}

bool checkforlondon(vector<string> &game){
    vector<string> london;
    london.push_back("BR BN BB BQ BK BB 11 BR");
    london.push_back("BP BP BP 11 BP BP BP BP");
    london.push_back("11 11 11 11 11 BN 11 11");
    london.push_back("11 11 11 BP 11 11 11 11");
    london.push_back("11 11 11 WP 11 WB 11 11");
    london.push_back("11 11 11 11 11 WN 11 11");
    london.push_back("WP WP WP 11 WP WP WP WP");
    london.push_back("WR WN 11 WQ WK WB 11 WR");
    for(int j=0;j<game.size();j++){
        if(game[j]!=london[j]){
            return false;
        }
    }
    return true;
}

bool checkforbenonidefense(vector<string> &game){
    vector<string> benonidefense;
    benonidefense.push_back("BR BN BB BQ BK BB 11 BR");
    benonidefense.push_back("BP BP 11 BP BP BP BP BP");
    benonidefense.push_back("11 11 11 11 11 BN 11 11");
    benonidefense.push_back("11 11 BP 11 11 11 11 11");
    benonidefense.push_back("11 11 WP WP 11 11 11 11");
    benonidefense.push_back("11 11 11 11 11 11 11 11");
    benonidefense.push_back("WP WP 11 11 WP WP WP WP");
    benonidefense.push_back("WR WN WB WQ WK WB WN WR");
    for(int i=0;i<game.size();i++){
        if(game[i]!=benonidefense[i]){
            return false;
        }
    }
    return true;
}

bool checkforcatalan(vector<string> &game){
    vector<string> catalan;
    catalan.push_back("BR BN BB BQ BK BB 11 BR");
    catalan.push_back("BP BP BP BP 11 BP BP BP");
    catalan.push_back("11 11 11 11 BP BN 11 11");
    catalan.push_back("11 11 11 11 11 11 11 11");
    catalan.push_back("11 11 WP WP 11 11 11 11");
    catalan.push_back("11 11 11 11 11 11 WP 11");
    catalan.push_back("WP WP 11 11 WP WP 11 WP");
    catalan.push_back("WR WN WB WQ WK WB WN WR");
    for(int i=0;i<game.size();i++){
        if(game[i]!=catalan[i]){
            return false;
        }
    }
    return true;
}

bool checkforreti(vector<string> &game){
    vector<string> reti;
    reti.push_back("BR BN BB BQ BK BB BN BR");
    reti.push_back("BP BP BP BP BP BP BP BP");
    reti.push_back("11 11 11 11 11 11 11 11");
    reti.push_back("11 11 11 11 11 11 11 11");
    reti.push_back("11 11 11 11 11 11 11 11");
    reti.push_back("11 11 11 11 11 WN 11 11");
    reti.push_back("WP WP WP WP WP WP WP WP");
    reti.push_back("WR WN WB WQ WK WB 11 WR");
    for(int i=0;i<game.size();i++){
        if(game[i]!=reti[i]){
            return false;
        }
    }
    return true;
}

bool checkforenglish(vector<string> &game){
    vector<string> english;
    english.push_back("BR BN BB BQ BK BB BN BR");
    english.push_back("BP BP BP BP BP BP BP BP");
    english.push_back("11 11 11 11 11 11 11 11");
    english.push_back("11 11 11 11 11 11 11 11");
    english.push_back("11 11 WP 11 11 11 11 11");
    english.push_back("11 11 11 11 11 11 11 11");
    english.push_back("WP WP 11 WP WP WP WP WP");
    english.push_back("WR WN WB WQ WK WB WN WR");
    for(int i=0;i<game.size();i++){
        if(game[i]!=english[i]){
            return false;
        }
    }
    return true;
}

bool checkforbird(vector<string> &game){
    vector<string> bird;
    bird.push_back("BR BN BB BQ BK BB BN BR");
    bird.push_back("BP BP BP BP BP BP BP BP");
    bird.push_back("11 11 11 11 11 11 11 11");
    bird.push_back("11 11 11 11 11 11 11 11");
    bird.push_back("11 11 11 11 11 WP 11 11");
    bird.push_back("11 11 11 11 11 11 11 11");
    bird.push_back("WP WP WP WP WP 11 WP WP");
    bird.push_back("WR WN WB WQ WK WB WN WR");
    for(int i=0;i<game.size();i++){
        if(game[i]!=bird[i]){
            return false;
        }
    }
    return true;
}

bool checkforkingsindianattack(vector<string> &game){
    vector<string> kingsindianattack;
    kingsindianattack.push_back("BR BN BB BQ BK BB BN BR");
    kingsindianattack.push_back("BP BP BP 11 BP BP BP BP");
    kingsindianattack.push_back("11 11 11 11 11 11 11 11");
    kingsindianattack.push_back("11 11 11 BP 11 11 11 11");
    kingsindianattack.push_back("11 11 11 11 11 11 11 11");
    kingsindianattack.push_back("11 11 11 11 11 WN WP 11");
    kingsindianattack.push_back("WP WP WP WP WP WP 11 WP");
    kingsindianattack.push_back("WR WN WB WQ WK WB 11 WR");
    for(int i=0;i<game.size();i++){
        if(game[i]!=kingsindianattack[i]){
            return false;
        }
    }
    return true;
}

bool checkforhungarian(vector<string> &game){
    vector<string> hungarian;
    hungarian.push_back("BR BN BB BQ BK BB BN BR");
    hungarian.push_back("BP BP BP BP BP BP BP BP");
    hungarian.push_back("11 11 11 11 11 11 11 11");
    hungarian.push_back("11 11 11 11 11 11 11 11");
    hungarian.push_back("11 11 11 11 11 11 11 11");
    hungarian.push_back("11 11 11 11 11 11 WP 11");
    hungarian.push_back("WP WP WP WP WP WP 11 WP");
    hungarian.push_back("WR WN WB WQ WK WB WN WR");
    for(int i=0;i<game.size();i++){
        if(game[i]!=hungarian[i]){
            return false;
        }
    }
    return true;
}

bool checkfornimzolarsen(vector<string> &game){
    vector<string> nimzolarsen;
    nimzolarsen.push_back("BR BN BB BQ BK BB BN BR");
    nimzolarsen.push_back("BP BP BP BP BP BP BP BP");
    nimzolarsen.push_back("11 11 11 11 11 11 11 11");
    nimzolarsen.push_back("11 11 11 11 11 11 11 11");
    nimzolarsen.push_back("11 11 11 11 11 11 11 11");
    nimzolarsen.push_back("11 WP 11 11 11 11 11 11");
    nimzolarsen.push_back("WP 11 WP WP WP WP WP WP");
    nimzolarsen.push_back("WR WN WB WQ WK WB WN WR");
    for(int i=0;i<game.size();i++){
        if(game[i]!=nimzolarsen[i]){
            return false;
        }
    }
    return true;
}

void showsicilianvariations(){
    cout<<"This is a game of Sicilian Defense"<<endl;
    cout<<"In the Sicilian Defense opening, White has 33% chance of winning and black has 26% chance of winning and the percentage of a draw is 42%"<<endl;
    cout<<"Most common further continuations of the game are as follows"<<endl;
    cout<<"2.Nf3 d6 3.d4 cxd4 4.Nxd4 Nf6 5.Nc3 a6"<<endl;
    cout<<"This leads to the Sicilian Defense Najdorf Variation"<<endl;
    cout<<"In the Najdorf variation, White has 29% chance of winning and black has 23% chance of winning and the percentage of a draw is 48%"<<endl;
    cout<<"2.Nf3 d6 3.d4 cxd4 4.Nxd4 Nf6 5.Nc3 g6"<<endl; 
    cout<<"2.c3"<<endl;
    cout<<"This leads to the Sicilian Defense Alapin Variation"<<endl;
    cout<<"In the Alapin Variation, White has 29% chance of winning and Black has 27% chance of winning and the percentage of a Draw is 44%"<<endl;
    cout<<"2.c3 d5 3.exd5 Qxd5"<<endl;
    cout<<"This leads to the Sicilian Defense Barmen Variation"<<endl;
    cout<<"In the Barmen Defense Variation, White has 28% chance of winning and Black has 26% chance of winning and the percentage of a Draw is 46%"<<endl;
    cout<<"This leads to the Sicilian Defense Dragon Variation"<<endl;
    cout<<"In the Dragon Variation, White has 39% chance of winning and Black has 23% chance of winning and the percentage of a Draw is 37%"<<endl;
    cout<<"2.Nf3 d6 3.d4 cxd4 4.Nxd4 Nf6 5.Nc3 Nc6"<<endl;
    cout<<"This leads to the Sicilian Defense Classical Variation"<<endl;
    cout<<"In the Classical Variation, White has 34% chance of winning and Black has 29% chance of winning and the percentage of a Draw is 37%"<<endl;
    cout<<"2.Nf3 d6 3.d4 cxd4 4.Nxd4 Nf6 5.Nc3 e6"<<endl;
    cout<<"This leads to the Sicilian Defense Scheveningen Variation"<<endl;
    cout<<"In the Scheveningen Variation, White has 37% of winning and Black has 27% chance of winning and the percentage of a Draw is 36%"<<endl;
    cout<<"2.Nf3 Nc6 3.d4 cxd4 4.Nxd4 Nf6 5.Nc3 e5"<<endl;
    cout<<"This leads to the Sicilian Defense Sveshnikov Variation"<<endl;
    cout<<"In the Sveshnikov Variation, White has 26% of winning and Black has 18% chance of winning and the percentage of a Draw is 56%"<<endl;
    cout<<"2.Nf3 Nc6 3.d4 cxd4 4.Nxd4 g6"<<endl;
    cout<<"This leads to the Sicilian Defense Accelerated Dragon"<<endl;
    cout<<"In the Accelerated Dragon, White has 32% chance of winning and Black has 23% chance of winning and the percentage of a Draw is 45%"<<endl;
    cout<<"2.Nf3 Nc6 3.d4 cxd4 4.Nxd4 e5 5.Nb5 d6"<<endl;
    cout<<"This leads to the Sicilian Defense Kalashnikov Variation"<<endl;
    cout<<"In the Kalashnikov Variation, White has 33% chance of winning and Black has 25% chance of winning and the percentage of a Draw is 42%"<<endl;
    cout<<"2.Nf3 e6 3.d4 cxd4 4.Nxd4 Nc6"<<endl;
    cout<<"This leads to the Sicilian Defense Taimanov Variation"<<endl;
    cout<<"In the Taimanov Variation, White has 34% chance of winning and Black has 26% chance of winning and the percentage of a Draw is 40%"<<endl;
    cout<<"2.Nf3 e6 3.d4 cxd4 4.Nxd4 a6"<<endl;
    cout<<"This leads to the Sicilian Defense Kan Variation"<<endl;
    cout<<"In the Kan Variation, White has 34% chance of winning and Black has 31% chance of winning and the percentage of a Draw is 35%"<<endl;
    cout<<"2.Nf3 d6 3.Bb5+"<<endl;
    cout<<"This leads to the Sicilian Defense Moscow Variation"<<endl;
    cout<<"In the Moscow Variation, White has 28% chance of winning and Black has 25% chance of winnning and the percentage of a Draw is 47%"<<endl;
    cout<<"2.Nf3 Nc6 3.Bb5"<<endl;
    cout<<"This leads to the Sicilian Defense Rossolimo Variation"<<endl;
    cout<<"In the Rossolimo Variation, White has 35% chance of winning and Black has 24% chance of winning and the percentage of a Draw is 41%"<<endl;
    cout<<"2.d4 cxd4 3.c3"<<endl;
    cout<<"This leads to the Sicilian Defense Smith Morra Gambit"<<endl;
    cout<<"In the Smith Morra Gambit, White has 26% chance of winning and Black has 39% chance of winning and the percentage of Draw is 35%"<<endl;
    cout<<"2.Nc3"<<endl;
    cout<<"This leads to the Sicilian Defense Closed Variation"<<endl;
    cout<<"In the Closed Variation, White has 32% chance of winning and Black has 31% chance of winning and the percentage of Draw is 37%"<<endl;
    cout<<"2.Nf3 Nc6 3.d4 cxd4 4.Nxd4"<<endl;
    cout<<"This leads to the Silician Defense Open Variation"<<endl;
    cout<<"In the Open Variation, White has 30% chance of winning and Black has 25% chance of winning and the percentage of Draw is 45%"<<endl;
    cout<<"2.Nc3 Nc6 3.f4"<<endl;
    cout<<"This leads to the Silician Defense Grand Prix Attack"<<endl;
    cout<<"In the Grand Prix Attack Variation, White has 28% chance of winning and Black has 37% chance of winning and the percentage of Draw is 35%"<<endl;
    cout<<"2.Nc3 Nc6 3.Nge2"<<endl;
    cout<<"This leads to the Silician Defense Closed Chameleon Variation"<<endl;
    cout<<"In the Chameleon Variation, White has 35% chance of winning and Black has 24% chance of winning and the percentage of Draw is 41%"<<endl;
}

void showfrenchvariations(){
    cout<<"This is a game of French Defense"<<endl;
    cout<<"In the French Defense Opening, White has 35% chance of winning and Black has 24%chance of winning and the percentage of Draw is 41%"<<endl;
    cout<<"Most Common further continuations of the game are as follows"<<endl;
    cout<<"2.d4 d5 3.Nc3"<<endl;
    cout<<"This leads to the French Defense Paulsen Variation"<<endl;
    cout<<"In the Paulsen Variation, White has 36% chance of winning and Black has 23% chance of winning and the percentage of a Draw is 41%"<<endl;
    cout<<"2.d4 d5 3.Nc3 Bb4"<<endl;
    cout<<"This leads to the French Defense Winawer Variation"<<endl;
    cout<<"In the Winawer Variation, White has 38% chance of winning and Black has 26% chance of winning and the percentage of a Draw is 38%"<<endl;
    cout<<"2.d4 d5 3.Nc3 Nf6"<<endl;
    cout<<"This leads to the French Defense Classical Variation"<<endl;
    cout<<"In the classical variation, White has 34% chance of winning and Black has 23% chance of winning and the percentage of a Draw is 43%"<<endl;
    cout<<"2.d4 d5 3.Nc3 Nf6 4.Bg5"<<endl;
    cout<<"This leads to the French Defense Burn Variation"<<endl;
    cout<<"In the Burn Variation, White has 32% chance of winning and Black has 23%chance of winning and the percentage of a Draw is 45%"<<endl;
    cout<<"2.d4 d5 3.Nc3 Nf6 4.e5 Nfd7"<<endl;
    cout<<"This leads to the French Defense Steinitz Variation"<<endl;
    cout<<"In the Steinitz Variation, White has 36% chance of winning and Black has 22% chance of winning and the percentage of a Draw is 42%"<<endl;
    cout<<"2.d4 d5 3.Nd2"<<endl;
    cout<<"This leads to the French Defense Tarrasch Variation"<<endl;
    cout<<"In the Tarrasch Variation, White has 36% chance of winning and Black has 22% chance of winning and the percentage of a Draw is 42%"<<endl;
    cout<<"2.d4 d5 3.e5 c5"<<endl;
    cout<<"This leads to the French Defense Advance Variation"<<endl;
    cout<<"In the Advance Variation, White has 35% chance of winning and Black has 30% chance of winning and the percentage of a Draw is 35%"<<endl;
    cout<<"2.d4 d5 3.exd5 exd5"<<endl;
    cout<<"This leads to the French Defense Exchange Variation"<<endl;
    cout<<"In the Exchange Variation, White has 19% chance of winning and Black has 24% chance of winning and the percentage of a Draw is 57%"<<endl;
}

void showruylopezvariations(){
    cout<<"This is a game of Ruy Lopez"<<endl;
    cout<<"In the Ruy Lopez opening, White has 30% chance of winning and Black has 20% chance of winnig and the percentage of a Draw is 50%"<<endl;
    cout<<"Most Common further continuations of the game are as follows"<<endl;
    cout<<"3.Bb5 a6"<<endl;
    cout<<"This leads to the Ruy Lopez Morphy Defense Variation"<<endl;
    cout<<"In the Morphy Defense Variation, White has 31% chance of winning and Black has 19% chance of winning and the percentage of a Draw is 50%"<<endl;
    cout<<"3.Bb5 a6 4.Bxc6 dxc6"<<endl;
    cout<<"This leads to the Ruy Lopex Exchanged Variation"<<endl;
    cout<<"In the Exchanged Variation, White has 26% chance of winning and Black has 20% chance of winning and the percentage of a Draw is 54%"<<endl;
    cout<<"3.Bb5 a6 4.Ba4 Nf6 5.O-O Nxe4 6.d4 b5 7.Bb3 d5 8.dxe5 Be6"<<endl;
    cout<<"This leads to the Ruy Lopez Open Defense Variation"<<endl;
    cout<<"In the Open Defense Variation, White has 32% chance of winning and Black has 18% chance of winning and the percentage of a Draw is 50%"<<endl;
    cout<<"3.Bb5 a6 4.Ba4 Nf6 5.O-O Be7"<<endl;
    cout<<"This leads to the Ruy Lopez Closed Variation"<<endl;
    cout<<"In the Closed Variation, White has 29% chance of winning and Black has 16% chance of winning and the percentage of a Draw is 55%"<<endl;
    cout<<"3.Bb5 a6 4.Ba4 Nf6 5.O-O Be7 6.d3"<<endl;
    cout<<"This leads to the Ruy Lopez Martinez Variation"<<endl;
    cout<<"In the Martinez Variation, White has 33% chance of winning and Black has 19% chance of winning and the percentage of a Draw is 48%"<<endl;
    cout<<"3.Bb5 a6 4.Ba4 Nf6 5.O-O Be7 6.Re1 b5 7.Bb3 0-0 8.c3 d5"<<endl;
    cout<<"This leads to the Ruy Lopez Marshall Attack"<<endl;
    cout<<"In the Marshall Attack Variation, White has 19% chance of winning and Black has 1% chance of winning and the percentage of a Draw is 68%"<<endl;
    cout<<"3.Bb5 a6 4.Ba4 Nf6 5.0-0 Be7 6.Re1 b5 7.Bb3 d6 8.c3 0-0 9.h3 Na5 10.Bc2 c5 11.d4 Qc7"<<endl;
    cout<<"This leads to the Ruy Lopez Chigorin Defense Variation"<<endl;
    cout<<"In the Chigorin Defense Variation, White has 34% chance of winning and Black has 15% chance of winning and the percentage of a Draw is 51%"<<endl;
    cout<<"3.Bb5 a6 4.Ba4 Nf6 5.0-0 Be7 6.Re1 b5 7.Bb3 d6 8.c3 0-0 9.h3 Nb8"<<endl;
    cout<<"This leads to the Ruy Lopez Breyer Variation"<<endl;
    cout<<"In the Breyer Defense Variation, White has 28% chance of winning and Black has 17% chance of winning and the percentage of a Draw is 55%"<<endl;
    cout<<"3.Bb5 a6 4.Ba4 Nf6 5.0-0 Be7 6.Re1 b5 7.Bb3 d6 8.c3 0-0 9.h3 Bb7"<<endl;
    cout<<"This leads to the Ruy Lopez Zaitsev Variation"<<endl;
    cout<<"In the Zaitsev Variation, White has 25% chance of winning and Black 12% chance of winning and percentage of a Draw is 63%"<<endl;
    cout<<"3.Bb5 Nge7"<<endl;
    cout<<"This leads to the Ruy Lopez Cozio Defense Variation"<<endl;
    cout<<"In this Cozio Defense Variation, White has 37% chance of winning and Black has 25% chance of winning and the percentage of a Draw is 38%"<<endl;
    cout<<"3.Bb5 g6"<<endl;
    cout<<"This leads to the Ruy Lopez Fianchetto Defense Variation"<<endl;
    cout<<"In the Fianchetto Defense Variation, White has 34% chance of winning and Black has 24% chance of winning and the percentage of a Draw is 42%"<<endl;
    cout<<"3.Bb5 Nd4"<<endl;
    cout<<"This leads to the Ruy Lopez Bird's Defense Variation"<<endl;
    cout<<"In the Bird's Defense Variation, White has 41% chance of winning and Black has 24% chance of winning and the percentage of a Draw is 35%"<<endl;
    cout<<"3.Bb5 f5"<<endl;
    cout<<"This leads to the Ruy Lopez Schliemann Defense Variation"<<endl;
    cout<<"In the Schliemann Defense Variation, White has 40% chance of winning and Black has 20% chance of winning and the percentage of a Draw is 40%"<<endl;
    cout<<"3.Bb5 Bc5"<<endl;
    cout<<"This leads to the Ruy Lopez Classical Defense Variation"<<endl;
    cout<<"In the Classical Defense Variation, White has 38% chance of winning and Black has 22% chance of winning and the percentage of a Draw is 40%"<<endl;
    cout<<"3.Bb5 Nf6"<<endl;
    cout<<"This leads to the Ruy Lopez Berlin Defense Variation"<<endl;
    cout<<"In the Berlin Defense Variation, White has 25% chance of winning and Black has 18% chance of winning and the percentage of a Draw is 57%"<<endl;
}

void showcarokannvariations(){
    cout<<"This is a game of Caro-Kann Defense"<<endl;
    cout<<"In the Caro-Kann opening, White has 32% chance of winning and Black has 25% chance of winning and the percentage of a Draw is 43%"<<endl;
    cout<<"Most Common further continuations of the game are as follows"<<endl;
    cout<<"2.d4 d5 3.Nc3 and 3.Nd2 dxe4 4.Nxe4 Bf5"<<endl;
    cout<<"This leads to the Caro-Kann Defense Classical Variation"<<endl;
    cout<<"In the Classical Variation, White has 26% chance of winning and Black has 22% chance of winning and the percentage of a Draw is 52%"<<endl;
    cout<<"2.d4 d5 3.Nc3 and 3.Nd2 dxe4 4.Nxe4 Nd7"<<endl;
    cout<<"This leads to the Caro-Kann Karpov Variation"<<endl;
    cout<<"In the Karpov Variation, White has 31% chance of winning and Black has 21% chance of winning and the percentage of a Draw is 48%"<<endl;
    cout<<"2.d4 d5 3.Nc3 and 3.Nd2 dxe4 4.Nxe4 Nf6 5.Nxf6+ gxf6"<<endl;
    cout<<"This leads to the Caro-Kann Bronstein Larsen Variation"<<endl;
    cout<<"In the Bronstein Larsen Variation, White has 41% chance of winning and Black has 23% chance of winning and the percentage of a Draw is 36%"<<endl;
    cout<<"2.d4 d5 3.Nc3 and 3.Nd2 dxe4 4.Nxe4 Nf6 5.Nxf6+ exf6"<<endl;
    cout<<"This leads to the Caro-Kann Korchnoi Variation"<<endl;
    cout<<"In the Korchnoi Variation, White has 32% chance of winning and Black has 22% chance of winning and the percentage of a Draw is 46%"<<endl;
    cout<<"2.d4 d5 3.Nc3 g6"<<endl;
    cout<<"This leads to the Caro-Kann Gurgenidze Variation"<<endl;
    cout<<"In the Gurgenidze Variation, White has 39% chance of winning and Black has 25% chance of winning and the percentage of a Draw is 36%"<<endl;
    cout<<"1.e4 c6 2.d4 d5 3.e5 Bf5"<<endl;
    cout<<"This leads to the Caro-Kann Advance Variation"<<endl;
    cout<<"In the Advance Variation, White has 36% chance of winning and Black has 23% chance of winning and the percentage of a Draw is 41%"<<endl;
    cout<<"2.d4 d5 3.exd5 cxd5"<<endl;
    cout<<"This leads to the Caro-Kann Exchange Variation"<<endl;
    cout<<"In the Exchange Variation, White has 29% chance of winning and Black has 26% chance of winning and the percentage of a Draw is 45%"<<endl;
    cout<<"2.d4 d5 3.exd5 cxd5 4.c4"<<endl;
    cout<<"This leads to the Caro-Kann Panov-Botvinnik Attack Variation"<<endl;
    cout<<"In the Panov Botvinnik Variation, White has 31% chance of winning and Black has 23% chance of winning and the percentage of a Draw is 46%"<<endl;
    cout<<"2.Nc3 d5 3.Nf3 (or 2.Nf3 d5 3.Nc3)"<<endl;
    cout<<"This leads to the Caro-Kann Two Knights Attack Variation"<<endl;
    cout<<"In the Two Knights Attack Variation, White has 33% chance of winning and Black has 27% chance of winning and the percentage of a Draw is 40%"<<endl;
}

void showitalianvariations(){
    cout<<"This is an Italian Game"<<endl;
    cout<<"In the Italian Opening, White has 31% chance of winning and Black has 26% chance of winning and the percentage of a Draw is 43%"<<endl;
    cout<<"Most Common further continuations of the game are as follows"<<endl;
    cout<<"3.Bc4 Bc5"<<endl;
    cout<<"This leads to the Italian Game Giuoco Piano Variation"<<endl;
    cout<<"In the Giuoco Piano Variation, White has 30% chance of winning and Black has 25% chance of winning and the percentage of a Draw is 45%"<<endl;
    cout<<"3.Bc4 Nf6"<<endl;
    cout<<"This leads to the Italian Game Two Knights Defense"<<endl;
    cout<<"In the Two Knights Defense Variation, White has 33% chance of winning and Black has 27% chance of winning and the percentage of a Draw is 40%"<<endl;
    cout<<"3.Bc4 Nf6 4.Nf5"<<endl;
    cout<<"This leads to thr Italian Game Fried Liver Attack"<<endl;
    cout<<"In the Fried Liver Attack, White has 36% chance of winning and Black has 28% chance of winning and the percentage of a Draw is 36%"<<endl;
    cout<<"3.Bc4 Bc5 4.Nc3 Nf6"<<endl;
    cout<<"This leads to the Italian Game Four Knights Variation"<<endl;
    cout<<"In the Four Knights Game, White has 21% chance of winning and Black has 26% chance of winning and the percentage of a Draw is 53%"<<endl;
    cout<<"3.Bc4 Nf6 4.b4"<<endl;
    cout<<"This leads to the Italian Game Evans Gambit Variation"<<endl;
    cout<<"In the Evans Gambit Variation, White has 31% chance of winning and Black has 32% chance of winning and the percentage of a Draw is 37%"<<endl;
    cout<<"3.Bc4 Be7"<<endl;
    cout<<"This leads to the Italian Game Hungarian Defense Variation"<<endl;
    cout<<"In the Hungarian Defense Variation, White has 41% chance of winning and Black has 23% chance of winning and the percentage of a Draw is 36%"<<endl;
    cout<<"3.Bc4 Nf6 4.d4 exd4 5.O-O Bc5 6.e5"<<endl;
    cout<<"This leads to the Italian Game Max Lange Attack"<<endl;
    cout<<"In the Max Lange Attack Variation, White has 37% chance of winning and Black has 34% chance of winning and the percentage of a Draw is 29%"<<endl;
    cout<<"3.Bc4 d6"<<endl;
    cout<<"This leads to the Semi Italian Game Variation"<<endl;
    cout<<"In the Semi Italian Variation, White has 41% chance of winning and Black has 26% chance of winning and the percentage of a Draw is 33%"<<endl;
}

void showscandinavianvariations(){
    cout<<"This is a game of Scandinavian Defense"<<endl;
    cout<<"In the Scandinavian Defense Opening, White has 39% chance of winning and Black has 24% chance of winning and the percentage of a Draw is 37%"<<endl;
    cout<<"Most Common further continuations of the game are as follows"<<endl;
    cout<<"2.exd5 Qxd5"<<endl;
    cout<<"This leads to the Scandinavian Defense Mieses-Kotroc Variation"<<endl;
    cout<<"In the Mieses-Kotroc Variation, White has 38% chance of winning and Black has 23% chance of winning and the percentage of a Draw is 39%"<<endl;
    cout<<"2.d4"<<endl;
    cout<<"This leads to the Scandinavian Defense BlackMar Gambit Variation"<<endl;
    cout<<"In the BlackMar Gambit Variation, White has 26% chance of winning and Black has 42% chance of winning and the percentage of a Draw is 32%"<<endl;
    cout<<"2.Nf3"<<endl;
    cout<<"This leads to the Zukertort Opening Tennison Gambit"<<endl;
    cout<<"In the Tennison Gambit Variation, White has 18% chance of winning and Black has 60% chance of winning and the percentage of a Draw is 22%"<<endl;
    cout<<"2.exd5 Nf6"<<endl;
    cout<<"This leads to the Scandinavian Defense Modern Variation"<<endl;
    cout<<"In the Modern Variation, White has 41% chance of winning and Black has 24% chance of winning and the percentage of a Draw is 35%"<<endl;
    cout<<"2.exd5 Qxd5 3.Nc3 Qd6"<<endl;
    cout<<"This leads to the Scandinavian Defense Gubinsky-Melts Defense"<<endl;
    cout<<"In the Gubinsky-Melts Variation, White has 35% chance of winning and Black has 25% chance of winning and the percentage of a Draw is 40%"<<endl;
}

void showpircdefensevariations(){
    cout<<"This is a game of Pirc Defense"<<endl;
    cout<<"In the Pirc Defense Opening, White has 38% chance of winning and Black has 25% chance of winning and the percentage of a Draw is 37%"<<endl;
    cout<<"Most Common further continuations of the game are as follows"<<endl;
    cout<<"3.Nc3 g6 4.f4 Bg7 5.Nf3"<<endl;
    cout<<"This leads to the Pirc Defense Austrian Attack Variation"<<endl;
    cout<<"In the Austrian Attack Variation, White has 36% chance of winning and Black has 25% chance of winning and the percentage of a Draw is 39%"<<endl;
    cout<<"3.Nc3 g6 4.Nf3"<<endl;
    cout<<"This leads to the Pirc Defense Classical Variation"<<endl;
    cout<<"In the Classical Variation, White has 32% chance of winning and Black has 24% chance of winning and the percentage of a Draw is 44%"<<endl;
    cout<<"3.Nc3 g6 4.f4 Bg7 5.Nf3 O-O 6.Bd3"<<endl;
    cout<<"This leads to the Pirc Defense Weiss Variation"<<endl;
    cout<<"In the Weiss Variation, White has 36% chance of winning and Black has 26% chance of winning and the percentage of a Draw is 38%"<<endl;
    cout<<"3.Nc3 g6 4.f4 Bg7 5.Nf3 c4"<<endl;
    cout<<"This leads to the Pirc Defense Dragon Formation Variation"<<endl;
    cout<<"In the Dragon Formation Variation, White has 35% chance of winning and Black has 19% chance of winning and the percentage of a Draw is 46%"<<endl;
    cout<<"3.Nc3 g6 4.Be3 c6 5.Qd2"<<endl;
    cout<<"This leads to the Pirc Defense 150 Attack Variation"<<endl;
    cout<<"In the 150 Attack Variation, White has 44% chance of winning and Black has 24% chance of winning and the percentage of a Draw is 32%"<<endl;
    cout<<"3.Nc3 g6 4.Bg5"<<endl;
    cout<<"This leads to the Pirc Defense Byrne Variation"<<endl;
    cout<<"In the Byrne Variation, White has 44% chance of winning and Black has 24% chance of winning and the percentage of a Draw is 32%"<<endl;
    cout<<"3.Nc3 c6"<<endl;
    cout<<"This leads to the Czech Defense Variation"<<endl;
    cout<<"In the Czech Defense Variation, White has 43% chance of winning and Black has 27% chance of winning and the percentage of a Draw is 30%"<<endl;
}

void showalekhinedefensevariations(){
    cout<<"This is a game of Alekhine Defense"<<endl;
    cout<<"In the Alekhine Defense, White has 37% chance of winning and Black has 26% chance of winning and the percentage of a Draw is 37%"<<endl;
    cout<<"Most Common further continuations of the game are as follows"<<endl;
    cout<<"2.e5 Nd5 3.d4 d6 4.Nf3"<<endl;
    cout<<"This leads to the Alekhine Defense Modern Variation"<<endl;
    cout<<"In the Modern Variation, White has 39% chance of winning and Black has 22% chance of winning and the percentage of a Draw is 39%"<<endl;
    cout<<"2.e5 Nd5 3.d4 d6 4.c4 Nb6 5.f4"<<endl;
    cout<<"This leads to the Alekhine Defense Four Pawns Attack Variation"<<endl;
    cout<<"In the Four Pawns Attack Variation, White has 39% chance of winning and Black has 22% chance of winning and the percentage of a Draw is 39%"<<endl;
    cout<<"2.e5 Nd5 3.d4 d6 4.c4 Nb6 5.exd6"<<endl;
    cout<<"This leads to the Alekhine Defense Exchange Variation"<<endl;
    cout<<"In the Exchange Variation, White has 39% chance of winning and Black has 25% chance of winning and the percentage of a Draw is 36%"<<endl;
    cout<<"2.e5 Nd5 3.d4 d6 4.c4 Nb6 5.exd6 cxd6 6.Nc3 g6 7.Be3 Bg7 8.Rc1 0-0 9.b3"<<endl;
    cout<<"This leads to the Alekhine Defense Voronezh Variation"<<endl;
    cout<<"In the Voronezh Variation, White has 41% chance of winning and Black has 22% chance of winning and the percentage of a Draw is 37%"<<endl;
    cout<<"2.e5 Nd5 3.d4 d6 4.Nf3 g6"<<endl;
    cout<<"This leads to the Alekhine Defense Alburt Variation"<<endl;
    cout<<"In the Alburt Variation, White has 40% chance of winning and Black has 21% chance of winning and the percentage of a Draw is 39%"<<endl;
    cout<<"2.e5 Nd5 3.d4 d6 4.Nf3 dxe5"<<endl;
    cout<<"This leads to the Alekhine Defense Larsen Variation"<<endl;
    cout<<"In the Larsen Variation, White has 36% chance of winning and Black has 20% chance of winning and the percentage of a Draw is 44%"<<endl;
    cout<<"2.e5 Nd5 3.d4 d6 4.Bc4"<<endl;
    cout<<"This leads to the Alekhine Defense Balogh Variation"<<endl;
    cout<<"In the Balogh Variation, White has 37% chance of winning and Black has 30% chance of winning and the percentage of a Draw is 33%"<<endl;
    cout<<"2.e5 Nd5 3.c4 Nb6 4.c5"<<endl;
    cout<<"This leads to the Alekhine Two Pawns Attack Variation"<<endl;
    cout<<"In the Two Pawns Attack Variation, White has 34% chance of winning and Black has 31% chance of winning and the percentage of a Draw is 35%"<<endl;
    cout<<"2.e5 Nd5 3.Nc3"<<endl;
    cout<<"This leads to the Alekhine Defense Samisch Attack Variation"<<endl;
    cout<<"In the Samisch Attack Variation, White has 31% chance of winning and Black has 31% chance of winning and the percentage of a Draw is 38%"<<endl;
    cout<<"2.e5 Ng8"<<endl;
    cout<<"This leads to the Alekhine Defense Brooklyn Variation"<<endl;
    cout<<"In the Brooklyn Variation, White has 49% chance of winning and Black has 27% chance of winning and the percentage of a Draw is 24%"<<endl;
    cout<<"2.Nc3 d5"<<endl;
    cout<<"This leads to the Alekhine Defense Scandinavian Variation"<<endl;
    cout<<"In the Scandinavian Variation, White has 32% chance of winning and Black has 29% chance of winning and the percentage of a Draw is 39%"<<endl;
    cout<<"2.d3"<<endl;
    cout<<"This leads to the Alekhine Defense Maroczy Variation"<<endl;
    cout<<"In the Maroczy Variation, White has 31% chance of winning and Black has 38% chance of winning and the percentage of a Draw is 31%"<<endl;
}

void showkingsgambitvariations(){
    cout<<"This leads to a game of King's Gambit"<<endl;
    cout<<"In the King's Gambit Opening, White has 30% chance of winning and Black has 37% chance of winning and the percentage of a Draw is 33%"<<endl;
    cout<<"Most Common further continuations of the game are as follows"<<endl;
    cout<<"2.f4 exf4"<<endl;
    cout<<"This leads to the King's Gambit Accepted Variation"<<endl;
    cout<<"In the Accepted Variation, White has 29% chance of winning and Black has 38% chance of winning and the percentage of a Draw is 33%"<<endl;
    cout<<"2.f4 exf4 3.Nf3"<<endl;
    cout<<"This leads to the King's Knight's Gambit Variation"<<endl;
    cout<<"In the Knight's Gambit Variation, White has 30% chance of winning and Black has 37% chance of winning and the percentage of a Draw is 33%"<<endl;
    cout<<"2.f4 exf4 3.Nf3 g5 4.h4 g4 5.Ne5"<<endl;
    cout<<"This leads to the King's Gambit Accepted Kieseritzky Gambit Variation"<<endl;
    cout<<"In the Kieseritzky Gambit Variation, White has 28% chance of winning and Black has 36% chance of winning and the percentage of a Draw is 36%"<<endl;
    cout<<"2.f4 exf4 3.Nf3 h6"<<endl;
    cout<<"This leads to the King's Gambit Accepted Becker Defense Variation"<<endl;
    cout<<"In the Becker Defense Variation, White has 37% chance of winning and Black has 40% chance of winning and the percentage of a Draw is 23%"<<endl;
    cout<<"2.f4 exf4 3.Nf3 Ne7"<<endl;
    cout<<"This leads to the King's Gambit Accepted Bonsch-Osmolovsky Variation"<<endl;
    cout<<"In the Bonsch-Osmolovsky Variation, White has 21% chance of winning and Black has 42% chance of winning and the percentage of a Draw is 37%"<<endl;
    cout<<"2.f4 exf4 3.Nf3 Be7"<<endl;
    cout<<"This leads to the King's Gambit Accepted Cunningham Defense Variation"<<endl;
    cout<<"In the Cunningham Defense Variation, White has 31% chance of winning and Black has 39% chance of winning and the percentage of a Draw is 30%"<<endl;
    cout<<"2.f4 exf4 3.Nf3 Nf6"<<endl;
    cout<<"This leads to the King's Gambit Accepted Schallopp Defense Variation"<<endl;
    cout<<"In the Schallopp Defense Variation, White has 34% chance of winning and Black has 39% chance of winning and the percentage of a Draw is 27%"<<endl;
    cout<<"2.f4 exf4 3.Nf3 d5"<<endl;
    cout<<"This leads to the King's Gambit Accepted Modern Defense Variation"<<endl;
    cout<<"In the Modern Defense Variation, White has 29% chance of winning and Black has 42% chance of winning and the percentage of a Draw is 29%"<<endl;
    cout<<"2.f4 exf4 3.Nf3 d6"<<endl;
    cout<<"This leads to the King's Gambit Accepted Fischer Defense Variation"<<endl;
    cout<<"In the Fischer Defense Variation, White has 29% chance of winning and Black has 44% chance of winning and the percentage of a Draw is 27%"<<endl;
    cout<<"2.f4 exf4 3.Bc4"<<endl;
    cout<<"This leads to the King's Gambit Accepted Bishop's Gambit Variation"<<endl;
    cout<<"In the Bishop's Gambit Variation, White has 29% chance of winning and Black has 38% chance of winning and the percentage of a Draw is 33%"<<endl;
    cout<<"2.f4 d5"<<endl;
    cout<<"This leads to the King's Gambit Declined Falkbeer Counter Gambit Variation"<<endl;
    cout<<"In the Falkbeer Counter Gambit Variation, White has 38% chance of winning and Black has 29% chance of winning and the percentage of a Draw is 33%"<<endl;
    cout<<"2.f4 Bc5"<<endl;
    cout<<"This leads to the King's Gambit Declined Classical Variation"<<endl;
    cout<<"In the Classical Variation, White has 35% chance of winning and Black has 36% chance of winning and the percentage of a Draw is 29%"<<endl;
}

void showscotchgamevariations(){
    cout<<"This is a Scotch Game"<<endl;
    cout<<"In the Scotch Opening, White has 31% chance of winning and Black has 25% chance of winning and the percentage of a Draw is 44%"<<endl;
    cout<<"Most Common further continuations of the game are as follows"<<endl;
    cout<<"3.d4 exd4 4.Nxd4 Bc5"<<endl;
    cout<<"This leads to the Scotch Game Classical Variation"<<endl;
    cout<<"In the Classical Variation, White has 32% chance of winning and Black has 24% chance of winning and the percentage of a Draw is 44%"<<endl;
    cout<<"3.d4 exd4 4.Nxd4 Nf6"<<endl;
    cout<<"This leads to the Scotch Game Schmidt Variation"<<endl;
    cout<<"In the Schmidt Variation, White has 28% chance of winning and Black has 23% chance of winning and the percentage of a Draw is 49%"<<endl;
    cout<<"3.d4 exd4 4.Nxd4 Qh4"<<endl;
    cout<<"This leads to the Scotch Game Steinitz Variation"<<endl;
    cout<<"In the Steinitz Variation, White has 49% chance of winning and Black has 25% chance of winning and the percentage of a Draw is 26%"<<endl;
    cout<<"3.d4 exd4 4.Nxd4 Bb4+"<<endl;
    cout<<"This leads to the Scotch Game Malaniuk Variation"<<endl;
    cout<<"In the Malaniuk Variation, White has 34% chance of winning and Black has 26% chance of winning and the percentage of a Draw is 40%"<<endl;
    cout<<"3.d4 exd4 4.Bc4"<<endl;
    cout<<"This leads to the Scotch Game Scotch Gambit Variation"<<endl;
    cout<<"In the Scotch Gambit Variation, White has 26% chance of winning and Black has 24% chance of winning and the percentage of a Draw is 40%"<<endl;
    cout<<"3.d4 exd4 4.c3"<<endl;
    cout<<"This leads to the Scotch Game Goring Gambit Variation"<<endl;
    cout<<"In the Goring Gambit Variation, White has 32% chance of winning and Black has 33% chance of winning and the percentage of a Draw is 35%"<<endl;
    cout<<"3.d4 exd4 4.Bc4 Nf6"<<endl;
    cout<<"This leads to the Scotch Game Dubois Reti Defense Variation"<<endl;
    cout<<"In the Dubois Reti Defense Variation, White has 28% chance of winning and Black has 31% chance of winning and the percentage of a Draw is 41%"<<endl;
    cout<<"3.d4 exd4 4.Nxd4 Nf6 5.Nxc6 bxc6 6.e5"<<endl;
    cout<<"This leads to the Scotch Game Mieses Variation"<<endl;
    cout<<"In the Mieses Variation, White has 30% chance of winning and Black has 24% chance of winning and the percentage of a Draw is 46%"<<endl;
}

void showviennavariations(){
    cout<<"This is a Vienna Game"<<endl;
    cout<<"In the Vienna Opening, White has 32% chance of winning and Black has 27% chance of winning and the percentage of a Draw is 41%"<<endl;
    cout<<"Most Common further continuations of the game are as follows"<<endl;
    cout<<"2.Nc3 Nf6"<<endl;
    cout<<"This leads to the Vienna Game Falkbeer Variation"<<endl;
    cout<<"In the Falkbeer Variation, White has 30% chance of winning and Black has 28% chance of winning and the percentage of a Draw is 42%"<<endl;
    cout<<"2.Nc3 Nf6 3.Nf3"<<endl;
    cout<<"This leads to the Vienna Game Three Knights Variation"<<endl;
    cout<<"In the Three Knights Variation, White has 31% chance of winning and Black has 31% chance of winning and the percentage of a Draw is 38%"<<endl;
    cout<<"2.Nc3 Nf6 3.Nf3 Nc6"<<endl;
    cout<<"This leads to the Vienns Game Four Knights Variation"<<endl;
    cout<<"In the Four Knights Variation, White has 27% chance of winning and Black has 23% chance of winning and the percentage of a Draw is 50%"<<endl;
    cout<<"2.Nc3 Nf6 3.f4"<<endl;
    cout<<"This leads to the Vienna Gambit Variation"<<endl;
    cout<<"In the Vienna Gambit Variation, White has 28% chance of winning and Black has 33% chance of winning and the percentage of a Draw is 39%"<<endl;
    cout<<"2.Nc3 Nf6 3.Bc4"<<endl;
    cout<<"This leads to the Vienna Game Stanley Variation"<<endl;
    cout<<"In the Stanley Variation, White has 28% chance of winning and Black has 30% chance of winning and the percentage of a Draw is 42%"<<endl;
    cout<<"2.Nc3 Nf6 3.g3"<<endl;
    cout<<"This leads to the Vienna Game Mieses Variation"<<endl;
    cout<<"In the Mieses Variation, White has 34% chance of winning and Black has 24% chance of winning and the percentage of a Draw is 42%"<<endl;
    cout<<"2.Nc3 Nc6"<<endl;
    cout<<"This leads to the Vienna Game Max Lange Defense Variation"<<endl;
    cout<<"In the Max Lange Defense Variation, White has 33% chance of winning and Black has 29% chance of winning and the percentage of a Draw is 38%"<<endl;
    cout<<"2.Nc3 Nc6 3.g3"<<endl;
    cout<<"This leads to the Vienna Game Paulsen Variation"<<endl;
    cout<<"In the Paulsen Variation, White has 35% chance of winning and Black has 25% chance of winning and the percentage of a Draw is 40%"<<endl;
    cout<<"2.Nc3 Bc5"<<endl;
    cout<<"This leads to the Vienna Game Anderssen Defense Variation"<<endl;
    cout<<"In the Anderssen Defense Variation, White has 33% chance of winning and Black has 30% chance of winning and the percentage of a Draw is 37%"<<endl;
}

void showqueensgambitvariations(){
    cout<<"This is a game of Queen's Gambit Opening"<<endl;
    cout<<"In the Queen's Gambit Opening, White has 32% chance of winning and Black has 20% chance of winning and the percentage of a Draw is 48%"<<endl;
    cout<<"Most Common further continuations of the game are as follows"<<endl;
    cout<<"2.c4 e6"<<endl;
    cout<<"This leads to the Queen's Gambit Declined Variation"<<endl;
    cout<<"In the Declined Variation, White has 34% chance of winning and Black has 20% chance of winning and the percentage of a Draw is 46%"<<endl;
    cout<<"2.c4 e6 3.Nc3 c5"<<endl;
    cout<<"This leads to the Queen's Gambit Declined Tarrasch Defense Variation"<<endl;
    cout<<"In the Tarrasch Defense Variation, White has 38% chance of winning and Black has 20% chance of winning and the percentage of a Draw is 42%"<<endl;
    cout<<"2.c4 dxc4"<<endl;
    cout<<"This leads to the Queen's Gambit Accepted Variation"<<endl;
    cout<<"In the Accepted Variation, White has 32% chance of winning and Black has 21% chance of winning and the percentage of a Draw is 47%"<<endl;
    cout<<"2.c4 c6"<<endl;
    cout<<"This leads to the Slav Defense Variation"<<endl;
    cout<<"In the Slav Defense Variation, White has 32% chance of winning and Black has 17% chance of winning and the percentage of a Draw is 51%"<<endl;
    cout<<"2.c4 c6 3.cxd5 cxd5"<<endl;
    cout<<"This leads to the Slav Defense Exchange Variation"<<endl;
    cout<<"In the Slav Defense Exchange Variation, White has 19% chance of winning and Black has 15% chance of winning and the percentage of a Draw is 66%"<<endl;
    cout<<"2.c4 c6 3.Nf3"<<endl;
    cout<<"This leads to the Slav Defense Modern Variation"<<endl;
    cout<<"In the Slav Defense Modern Variation, White has 31% chance of winning and Black has 19% chance of winning and the percentage of a Draw is 50%"<<endl;
    cout<<"2.c4 c6 3.Nf3 Nf6 4.e3"<<endl;
    cout<<"This leads to the Slav Defense Quiet Variation"<<endl;
    cout<<"In the Slav Defense Quiet Variation, White has 31% chance of winning and Black has 18% chance of winning and the percentage of a Draw is 51%"<<endl;
    cout<<"2.c4 c6 3.Nf3 Nf6 4.Nc3 a6"<<endl;
    cout<<"This leads to the Slav Defense Chameleon Variation"<<endl;
    cout<<"In the Slav Defense Chameleon Variation, White has 33% chance of winning and Black has 21% chance of winning and the percentage of a Draw is 46%"<<endl;
    cout<<"2.c4 c6 3.Nf3 Nf6 4.Nc3 dxc4 5.a4"<<endl;
    cout<<"This leads to the Slav Defense Alapin Variation"<<endl;
    cout<<"In the Slav Defense Alapin Variation, White has 34% chance of winning and Black has 20% chance of winning and the percentage of a Draw is 46%"<<endl;
    cout<<"2.c4 c6 3.Nf3 Nf6 4.Nc3 dxc4 5.e4"<<endl;
    cout<<"This leads to the Slav Defense Geller Gambit Variation"<<endl;
    cout<<"In the Geller Gambit Variation, White has 38% chance of winning and Black has 35% chance of winning and the percentage of a Draw is 27%"<<endl;
    cout<<"2.c4 c6 3.Nf3 Nf6 4.Nc3 dxc4 5.e3"<<endl;
    cout<<"This leads to the Slav Defense Alekhine Variation"<<endl;
    cout<<"In the Alekhine Variation, White has 32% chance of winning and Black has 25% chance of winning and the percentage of a Draw is 43%"<<endl;
    cout<<"2.c4 c6 3.Nf3 Nf6 4.Nc3 dxc4 5.a4 Bf5"<<endl;
    cout<<"This leads to the Slav Defense Czech Variation"<<endl;
    cout<<"In the Czech Variation, White has 34% chance of winning and Black has 19% chance of winning and the percentage of a Draw is 47%"<<endl;
    cout<<"2.c4 e5"<<endl;
    cout<<"This leads to the Queen's Gambit Declined Albin Countergambit Variation"<<endl;
    cout<<"In the Albin Countergambit Variation, White has 44% chance of winning and Black has 25% chance of winning and the percentage of a Draw is 31%"<<endl;
    cout<<"2.c4 Nc6"<<endl;
    cout<<"This leads to the Queen's Gambit Declined Chigorin Defense Variation"<<endl;
    cout<<"In the Chigorin Defense Variation, White has 44% chance of winning and Black has 22% chance of winning and the percentage of a Draw is 34%"<<endl;
    cout<<"2.c4 Bf5"<<endl;
    cout<<"This leads to the Queen's Gambir Declined Baltic Defense Variation"<<endl;
    cout<<"In the Baltic Defense Variation, White has 44% chance of winning and Black has 19% chance of winning and the percentage of a Draw is 37%"<<endl;
    cout<<"2.c4 c5"<<endl;
    cout<<"This leads to the Queen's Gambit Declined Austrian Defense Variation"<<endl;
    cout<<"In the Austrian Defense Variation, White has 40% chance of winning and Black has 17% chance of winning and the percentage of a Draw is 43%"<<endl;
    cout<<"2.c4 Nf6"<<endl;
    cout<<"This leads to the Queen's Gambit Declined Marshall Defense Variation"<<endl;
    cout<<"In the Marshall Defense Variation, White has 49% chance of winning and Black has 12% chance of winning and the percentage of a Draw is 39%"<<endl;
    cout<<"2.c4 c6 3.Nf3 Nf6 4.Nc3 e6"<<endl;
    cout<<"This leads to the Semi-Slav Defense Variation"<<endl;
    cout<<"In the Semi-Slav Defense Variation, White has 27% chance of winning and Black has 19% chance of winning and the percentage of a Draw is 54%"<<endl;
    cout<<"2.c4 e6 3.Nc3 Be7"<<endl;
    cout<<"This leads to the Queen's Gambit Declined Petrosian Variation"<<endl;
    cout<<"In the Petrosian Variation, White has 35% chance of winning and Black has 16% chance of winning and the percentage of a Draw is 49%"<<endl;
    cout<<"2.c4 e6 3.Nc3 a6"<<endl;
    cout<<"This leads to the Queen's Gambit Declined Janowski Variation"<<endl;
    cout<<"In the Janowski Variation, White has 32% chance of winning and Black has 26% chance of winning and the percentage of a Draw is 42%"<<endl;
    cout<<"2.c4 e6 3.Nc3 Nf6 4.Bg5 Be7 5.Nf3 h6 6.Bh4 O-O 7.e3 b6"<<endl;
    cout<<"This leads to the Queen's Gambit Declined Tartakower Defense Variation"<<endl;
    cout<<"In the Tartakower Defense Variation, White has 24% chance of winning and Black has 16% chance of winning and the percentage of a Draw is 60%"<<endl;
    cout<<"2.c4 e6 3.Nc3 Nf6 4.Bg5 Be7 5.Nf3 h6 6.Bh4 O-O 7.e3 Nbd7"<<endl;
    cout<<"This leads to the Queen's Gambit Declined Orthodox Defense Variation"<<endl;
    cout<<"In the Orthodox Defense Variation, White has 29% chance of winning and Black has 16% chance of winning and the percentage of a Draw is 55%"<<endl;
    cout<<"2.c4 e6 3.Nc3 Nf6 4.Bg5 Be7 5.Nf3 O-O 6.e3 h6 7.Bh4 Ne4"<<endl;
    cout<<"This leads to the Queen's Gambit Declined Lasker Defense Variation"<<endl;
    cout<<"In the Lasker Defense Variation, White has 22% chance of winning and Black has 10% chance of winning and the percentage of a Draw is 68%"<<endl;
    cout<<"2.c4 e6 3.Nc3 Nf6 4.cxd5 exd5"<<endl;
    cout<<"This leads to the Queen's Gambit Declined Exhange Variation"<<endl;
    cout<<"In the Exchange Variation, White has 38% chance of winning and Black has 16% chance of winning and the percentage of a Draw is 46%"<<endl;
    cout<<"2.c4 e6 3.Nc3 Nf6 4.Nf3 Bb4"<<endl;
    cout<<"This leads to the Queen's Gambit Declined Ragozin Defense Variation"<<endl;
    cout<<"In the Ragozin Defense Variation, White has 29% chance of winning and Black has 21% chance of winning and the percentage of a Draw is 50%"<<endl;
    cout<<"2.c4 e6 3.Nc3 Nf6 4.Nf3 Be7 5.Bf4"<<endl;
    cout<<"This leads to the Queen's Gambit Declined Harrwitz Attack Variation"<<endl;
    cout<<"In the Harrwitz Attack Variation, White has 34% chance of winning and Black has 13% chance of winning and the percentage of a Draw is 53%"<<endl;
}

void showkingsindiandefensevariations(){
    cout<<"This is a game of King's Indian Defense"<<endl;
    cout<<"In the King's Indian Defense Opening, White has 36% chance of winning and Black has 22% chance of winning and the percentage of a Draw is 42%"<<endl;
    cout<<"Most Common further continuations of the game are as follows"<<endl;
    cout<<"3.Nc3 Bg7 4.e4 d6 5.Nf3 0-0 6.Be2 e5"<<endl;
    cout<<"This leads to the King's Indian Defense Classical Variation"<<endl;
    cout<<"In the Classical Variation, White has 37% chance of winning and Black has 22% chance of winning and the percentage of a Draw is 41%"<<endl;
    cout<<"3.Nc3 Bg7 4.e4 d6 5.Nf3 0-0 6.Be2 e5 7.O-O Nc6 8.d5 Ne7"<<endl;
    cout<<"This leads to the King's Indian Defense Aronin-Taimanov Variation"<<endl;
    cout<<"In the Aronin-Taimanov Variation, White has 37% chance of winning and Black has 24% chance of winning and the percentage of a Draw is 39%"<<endl;
    cout<<"3.Nc3 Bg7 4.e4 d6 5.Nf3 0-0 6.Be2 e5 7.O-O Na6"<<endl;
    cout<<"This leads to the King's Indian Defense Glek Variation"<<endl;
    cout<<"In the Glek Defense Variation, White has 37% chance of winning and Black has 26% chance of winning and the percentage of a Draw is 37%"<<endl;
    cout<<"3.Nc3 Bg7 4.e4 d6 5.Nf3 0-0 6.Be2 e5 7.d5"<<endl;
    cout<<"This leads to the King's Indian Defense Petrosian Variation"<<endl;
    cout<<"In the Petrosian Variation, White has 38% chance of winning and Black has 26% chance of winning and the percentage of a Draw is 36%"<<endl;
    cout<<"3.Nc3 Bg7 4.e4 d6 5.Nf3 0-0 6.Be2 e5 7.Be3"<<endl;
    cout<<"This leads to the King's Indian Defense Gligoric-Taimanov Variation"<<endl;
    cout<<"In the Gligoric-Taimanov Variation, White has 40% chance of winning and Black has 20% chance of winning and the percentage of a Draw is 40%"<<endl;
    cout<<"3.Nc3 d5"<<endl;
    cout<<"This leads to the Grunfeld Defense Variation"<<endl;
    cout<<"In the Grunfeld Defense Variation, White has 30% chance of winning and Black has 22% chance of winning and the percentage of a Draw is 48%"<<endl;
    cout<<"3.Nc3 d5 4.f3"<<endl;
    cout<<"This leads to the Grunfeld Defense Lutikov Variation"<<endl;
    cout<<"In the Lutikov Variation, White has 30% chance of winning and Black has 40% chance of winning and the percentage of a Draw is 30%"<<endl;
    cout<<"3.Nc3 d5 4.h4"<<endl;
    cout<<"This leads to the Grunfeld Defense Zaitsev Gambit Variation"<<endl;
    cout<<"In the Zaitsev Gambit Variation, White has 39% chance of winning and Black has 23% chance of winning and the percentage of a Draw is 38%"<<endl;
    cout<<"3.Nc3 d5 4.Qb3"<<endl;
    cout<<"This leads to the Grunfeld Defense Russian Variation"<<endl;
    cout<<"In the Russian Variation, White has 36% chance of winning and Black has 16% chance of winning and the percentage of a Draw is 48%"<<endl;
    cout<<"3.Nc3 d5 4.Bg5"<<endl;
    cout<<"This leads to the Grunfeld Defense Stockholm Variation"<<endl;
    cout<<"In the Stockholm Variation, White has 33% chance of winning and Black has 25% chance of winning and the percentage of a Draw is 42%"<<endl;
    cout<<"3.Nc3 d5 4.Bf4"<<endl;
    cout<<"This leads to the Grunfeld Defense Brinckmann Attack Variation"<<endl;
    cout<<"In the Brinckmann Attack Variation, White has 30% chance of winning and Black has 21% chance of winning and the percentage of a Draw is 49%"<<endl;
    cout<<"3.Nc3 d5 4.cxd5 Nxd5"<<endl;
    cout<<"This leads to the Grunfeld Defense Exchange Variation"<<endl;
    cout<<"In the Exchange Variation, White has 30% chance of winning and Black has 21% chance of winning and the percentage of a Draw is 49%"<<endl;
    cout<<"4.Nf3 Bg7 5.Bg5"<<endl;
    cout<<"This leads to the Grunfeld Defense Petrosian Variation"<<endl;
    cout<<"In the Petrosian Variation, White has 28% chance of winning and Black has 28% chance of winning and the percentage of a Draw is 44%"<<endl;
    cout<<"3.Nc3 Bg7 4.e4 d6 5.Nf3 0-0 6.Be2 e5 7.dxe5 dxe5"<<endl;
    cout<<"This leads to the King's Indian Defense Exchange Variation"<<endl;
    cout<<"In the Exchange Variation, White has 18% chance of winning and Black has 19% chance of winning and the percentage of a Draw is 63%"<<endl;
    cout<<"3.Nc3 Bg7 4.e4 d6 5.f3"<<endl;
    cout<<"This leads to King's Indian Defense Samisch Variation"<<endl;
    cout<<"In the Samisch Variation, White has 39% chance of winning and Black has 25% chance of winning and the percentage of a Draw is 36%"<<endl;
    cout<<"3.Nc3 Bg7 4.e4 d6 5.Be2 0-0 6.Bg5"<<endl;
    cout<<"This leads to the King's Indian Defense Averbakh Variation"<<endl;
    cout<<"In the Averbakh Variation, White has 40% chance of winning and Black has 24% chance of winning and the percentage of a Draw is 36%"<<endl;
    cout<<"3.Nc3 Bg7 4.e4 d6 5.f4"<<endl;
    cout<<"This leads to the King's Indian Defense Four Pawns Attack Variation"<<endl;
    cout<<"In the Four Pawns Attack Variation, White has 39% chance of winning and Black has 26% chance of winning and the percentage of a Draw is 35%"<<endl;
    cout<<"3.Nf3 Bg7 4.g3"<<endl;
    cout<<"This leads to the King's Indian Defense Fianchetto Variation"<<endl;
    cout<<"In the Fianchetto Variation, White has 36% chance of winning and Black has 21% chance of winning and the percentage of a Draw is 43%"<<endl;
    cout<<"3.f3"<<endl;
    cout<<"This leads to the King's Indian Defense Alekhine Variation"<<endl;
    cout<<"In the Alekhine Variation, White has 38% chance of winning and Black has 26% chance of winning and the percentage of a Draw is 36%"<<endl;
}

void shownimzoindianvariations(){
    cout<<"This is a game of Nimzo-Indian Defense"<<endl;
    cout<<"In the Nimzo-Indian Opening, White has 30% chance of winning and Black has 24% chance of winning and the percentage of a Draw is 46%"<<endl;
    cout<<"Most Common further continuations of the game are as follows"<<endl;
    cout<<"4.Qc2"<<endl;
    cout<<"This leads to the Nimzo-Indian Defense Classical Variation"<<endl;
    cout<<"In the Classical Variation, White has 29% chance of winning and Black has 21% chance of winning and the percentage of a Draw is 50%"<<endl;
    cout<<"4.f3"<<endl;
    cout<<"This leads to the Nimzo-Indian Defense Kmoch Variation"<<endl;
    cout<<"In the Kmoch Variation, White has 31% chance of winning and Black has 25% chance of winning and the percentage of a Draw is 44%"<<endl;
    cout<<"4.Bg5"<<endl;
    cout<<"This leads to the Nimzo-Indian Defense Leningrad Variation"<<endl;
    cout<<"In the Leningrad Variation, White has 29% chance of winning and Black has 32% chance of winning and the percentage of a Draw is 39%"<<endl;
    cout<<"4.g3"<<endl;
    cout<<"This leads to the Nimzo-Indian Defense Romanishin Variation"<<endl;
    cout<<"In the Romanishin Variation, White has 31% chance of winning and Black has 24% chance of winning and the percentage of a Draw is 45%"<<endl;
    cout<<"4.Qb3"<<endl;
    cout<<"This leads to the Nimzo-Indian Defense Spielmann Variation"<<endl;
    cout<<"In the Spielmann Variation, White has 33% chance of winning and Black has 29% chance of winning and the percentage of a Draw is 38%"<<endl;
    cout<<"4.e3 c5"<<endl;
    cout<<"This leads to the Nimzo-Indian Defense Hubner Variation"<<endl;
    cout<<"In the Hubner Variation, White has 32% chance of winning and Black has 25% chance of winning and the percentage of a Draw is 43%"<<endl;
    cout<<"4.e3 b6"<<endl;
    cout<<"This leads to the Nimzo-Indian St.Petersburg Variation"<<endl;
    cout<<"In the St.Petersburg Variation, White has 33% chance of winning and Black has 28% chance of winning and the percentage of a Draw is 39%"<<endl;
    cout<<"4.O-O Ne2"<<endl;
    cout<<"This leads to the Nimzo-Indian Reshevsky Variation"<<endl;
    cout<<"In the Reshevsky Variation, White has 25% chance of winning and Black has 31% chance of winning and the percentage of a Draw is 44%"<<endl;
    cout<<"4.e3 b6 5.Ne2"<<endl;
    cout<<"This leads to the Nimzo-Indian Fischer Variation"<<endl;
    cout<<"In the Fischer Variation, White has 33% chance of winning and Black has 27% chance of winning and the percentage of a Draw is 40%"<<endl;
    cout<<"Qc2 Nc6"<<endl;
    cout<<"This leads to the Nimzo-Indian Defense Zurich Variation"<<endl;
    cout<<"In the Zurich Variation, White has 37% chance of winning and Black has 23% chance of winning and the percentage of a Draw is 40%"<<endl;
}

void showqueensindianvariations(){
    cout<<"This is a game of Queen's Indian Defense"<<endl;
    cout<<"In the Queen's Indian Defense Opening, White has 29% chance of winning and Black has 20% chance of winning and the percentage of a Draw is 51%"<<endl;
    cout<<"Most Common further continuations of the game are as follows"<<endl;
    cout<<"4.Bf4"<<endl;
    cout<<"This leads to the Queen's Indian Defense Miles Variation"<<endl;
    cout<<"In the Miles Variation, White has 38% chance of winning and Black has 24% chance of winning and the percentage of a Draw is 38%"<<endl;
    cout<<"4.e3"<<endl;
    cout<<"This leads to the Queen's Indian Defense Spassky Variation"<<endl;
    cout<<"In the Spassky Variation, White has 30% chance of winning and Black has 25% chance of winning and the percentage of a Draw is 45%"<<endl;
    cout<<"4.Nc3"<<endl;
    cout<<"This leads to the Queen's Indian Defense Kasparov Variation"<<endl;
    cout<<"In the Kasparov Variation, White has 32% chance of winning and Black has 24% chance of winning and the percentage of a Draw is 44%"<<endl;
    cout<<"4.a3"<<endl;
    cout<<"This leads to the Queen's Indian Defense Petrosian Variation"<<endl;
    cout<<"In the Petrosian Variation, White has 32% chance of winning and Black has 22% chance of winning and the percentage of a Draw is 46%"<<endl;
    cout<<"4.g3"<<endl;
    cout<<"This leads to the Queen's Indian Defense Fianchetto Variation"<<endl;
    cout<<"In the Fianchetto Variation, White has 27% chance of winning and Black has 18% chance of winning and the percentage of a Draw is 55%"<<endl;
    cout<<"4.g3 Ba6"<<endl;
    cout<<"This leads to the Queen's Indian Defense Nimzowitch Variation"<<endl;
    cout<<"In the Nimzowitch Variation, White has 26% chance of winning and Black has 19% chance of winning and the percentage of a Draw is 55%"<<endl;
}

void showbogoindianvariations(){
    cout<<"This is a game of Bogo-Indian Defense"<<endl;
    cout<<"In the Bogo-Indian Defense Opening, White has 34% chance of winning and Black has 21% chance of winning and the percentage of a Draw is 45%"<<endl;
    cout<<"Most Common further continuations of the game are as follows"<<endl;
    cout<<"4.Nbd2"<<endl;
    cout<<"This leads to the Bogo-Indian Defense Grunfeld Variation"<<endl;
    cout<<"In the Grunfeld Variation, White has 38% chance of winning and Black has 22% chance of winning and the percentage of a Draw is 40%"<<endl;
    cout<<"4.Nc3 b6"<<endl;
    cout<<"This leads to the Bogo-Indian Defense Duchamp Variation"<<endl;
    cout<<"In the Duchamp Variation, White has 33% chance of winning and Black has 26% chance of winning and the percentage of a Draw is 41%"<<endl;
    cout<<"4.Nc3 d5"<<endl;
    cout<<"This leads to the Bogo-Indian Defense Ragozin Variation"<<endl;
    cout<<"In the Ragozin Variation, White has 32% chance of winning and Black has 24% chance of winning and the percentage of a Draw is 44%"<<endl;
    cout<<"4.Bd2 Qe7"<<endl;
    cout<<"This leads to the Bogo-Indian Defense Nimzowitch Variation"<<endl;
    cout<<"In the Nimzowitch Variation, White has 34% chance of winning and Black has 19% chance of winning and the percentage of a Draw is 47%"<<endl;
    cout<<"4.Bd2 a5"<<endl;
    cout<<"This leads to the Bogo-Indian Defense Wade-Smyslov Variation"<<endl;
    cout<<"In the Wade-Smyslov Variation, White has 30% chance of winning and Black has 24% chance of winning and the percentage of a Draw is 46%"<<endl;
    cout<<"4.Bd2 c5"<<endl;
    cout<<"This leads to the Bogo-Indian Defense Vitolins Variation"<<endl;
    cout<<"In the Vitolins Variation, White has 31% chance of winning and Black has 21% chance of winning and the percentage of a Draw is 48%"<<endl;
    cout<<"4.Bd2 Bxd2+"<<endl;
    cout<<"This leads to the Bogo-Indian Defense Exchange Variation"<<endl;
    cout<<"In the Exchange Variation, White has 29% chance of winning and Black has 11% chance of winning and the percentage of a Draw is 60%"<<endl;
    cout<<"4.Bd2 Be7"<<endl;
    cout<<"This leads to the Bogo-Indian Defense Retreat Variation"<<endl;
    cout<<"In the Retreat Variation, White has 39% chance of winning and Black has 21% chance of winning and the percentage of a Draw is 40%"<<endl;
}

void showdutchdefensevariations(){
    cout<<"This is a game of Dutch Defense"<<endl;
    cout<<"In the Dutch Defense Opening, White has 38% chance of winning and Black has 24% chance of winning and the percentage of a Draw is 38%"<<endl;
    cout<<"Most Common further continuations of the game are as follows"<<endl;
    cout<<"2.g4"<<endl;
    cout<<"This leads to the Dutch Defense Krejcik Gambit Variation"<<endl;
    cout<<"In the Krejcik Gambit Variation, White has 34% chance of winning and Black has 41% chance of winning and the percentage of a Draw is 25%"<<endl;
    cout<<"2.Qd3"<<endl;
    cout<<"This leads to the Dutch Defense Alapin Variation"<<endl;
    cout<<"In the Alapin Variation, White has 34% chance of winning and Black has 37% chance of winning and the percentage of a Draw is 29%"<<endl;
    cout<<"2.h3"<<endl;
    cout<<"This leads to the Dutch Defense Korchnoi Attack Variation"<<endl;
    cout<<"In the Korchnoi Attack Variation, White has 37% chance of winning and Black has 33% chance of winning and the percentage of a Draw is 30%"<<endl;
    cout<<"2.e4"<<endl;
    cout<<"This leads to the Dutch Defense Staunton Gambit Variation"<<endl;
    cout<<"In the Staunton Gambit Variation, White has 34% chance of winning and Black has 35% chance of winning and the percentage of a Draw is 31%"<<endl;
    cout<<"2.Bg5"<<endl;
    cout<<"This leads to the Dutch Defense Hopton Attack Variation"<<endl;
    cout<<"In the Hopton Attack Variation, White has 42% chance of winning and Black has 21% chance of winning and the percentage of a Draw is 37%"<<endl;
    cout<<"2.Nc3"<<endl;
    cout<<"This leads to the Dutch Defense Raphael Variation"<<endl;
    cout<<"In the Raphael Variation, White has 39% chance of winning and Black has 26% chance of winning and the percentage of a Draw is 35%"<<endl;
    cout<<"2.g3"<<endl;
    cout<<"This leads to the Dutch Defense Fianchetto Attack Variation"<<endl;
    cout<<"In the Fianchetto Attack Variation, White has 38% chance of winning and Black has 21% chance of winning and the percentage of a Draw is 41%"<<endl;
    cout<<"2.c4 Nf6 3.Nf3 g6 4.g3 Bg7 5.Bg2"<<endl;
    cout<<"This leads to the Dutch Defense Leningrad Variation"<<endl;
    cout<<"In the Leningrad Variation, White has 35% chance of winning and Black has 27% chance of winning and the percentage of a Draw is 38%"<<endl;
    cout<<"2.c4 Nf6 3.g3 e6 4.Bg2"<<endl;
    cout<<"This leads to the Dutch Defense Classical Variation"<<endl;
    cout<<"In the Classical Variation, White has 38% chance of winning and Black has 21% chance of winning and the percentage of a Draw is 41%"<<endl;
    cout<<"2.c4 Nf6 3.Nf3 e6 4.g3 Be7 5.Bg2 O-O 6.O-O d5"<<endl;
    cout<<"This leads to the Dutch Defense Stonewall Variation"<<endl;
    cout<<"In the Stonewall Variation, White has 42% chance of winning and Black has 21% chance of winning and the percentage of a Draw is 37%"<<endl;
}

void showtrompowskyattackvariations(){
    cout<<"This is a game of Trompowsky Attack"<<endl;
    cout<<"In the Trompowsky Attack Opening, White has 34% chance of winning and Black has 29% chance of winning and the percentage of a Draw is 37%"<<endl;
    cout<<"Most Common further continuations of the game are as follows"<<endl;
    cout<<"2.Bg5 e6"<<endl;
    cout<<"This leads to the Trompowsky Attack Classical Defense Variation"<<endl;
    cout<<"In the Classical Defense Variation, White has 33% chance of winning and Black has 30% chance of winning and the percentage of a Draw is 37%"<<endl;
    cout<<"2.Bg5 Ne4 3.h4"<<endl;
    cout<<"This leads to the Trompowsky Attack Raptor Variation"<<endl;
    cout<<"In the Raptor Variation, White has 38% chance of winning and Black has 28% chance of winning and the percentage of a Draw is 34%"<<endl;
    cout<<"2.Bg5 Ne4 3.Bh4"<<endl;
    cout<<"This leads to the Trompowsky Attack Edge Variation"<<endl;
    cout<<"In the Edge Variation, White has 37% chance of winning and Black has 36% chance of winning and the percentage of a Draw is 27%"<<endl;
}

void showlondonvariations(){
    cout<<"This is a game of London System"<<endl;
    cout<<"In the London Opening, White has 28% chance of winning and Black has 27% chance of winning and the percentage of a Draw is 45%"<<endl;
    cout<<"Most Common further continuations of the game are as follows"<<endl;
    cout<<"3.Bf4 c5 4.e3 Qb6 5.Nc3"<<endl;
    cout<<"This leads to the London System Poisoned Pawn Variation"<<endl;
    cout<<"In the Poisoned Pawn Variation, White has 34% chance of winning and Black has 30% chance of winning and the percentage of a Draw is 36%"<<endl;
}

void showbenonidefensevariations(){
    cout<<"This is a game of Benoni Defense"<<endl;
    cout<<"In the Benoni Defense Opening, White has 41% chance of winning and Black has 26% chance of winning and the percentage of a Draw is 33%"<<endl;
    cout<<"Most Common further continuations of the game are as follows"<<endl;
    cout<<"3.d5 Ne4"<<endl;
    cout<<"This leads to the Vulture Defense Variation"<<endl;
    cout<<"In the Vulture Defense Variation, White has 52% chance of winning and Black has 24% chance of winning and the percentage of a Draw is 24%"<<endl;
    cout<<"3.d5 d6"<<endl;
    cout<<"This leads to the Benoni Defense Hromadka Variation"<<endl;
    cout<<"In the Hromadka Variation, White has 43% chance of winning and Black has 21% chance of winning and the percentage of a Draw is 36%"<<endl;
    cout<<"3.d5 e5"<<endl;
    cout<<"This leads to the Czech Benoni Defense Variation"<<endl;
    cout<<"In the Czech Benoni Defense Variation, White has 44% chance of winning and Black has 24% chance of winning and the percentage of a Draw is 32%"<<endl;
    cout<<"3.d5 e6"<<endl;
    cout<<"This leads to the Benoni Defense Modern Variation"<<endl;
    cout<<"In the Modern Variation, White has 44% chance of winning and Black has 26% chance of winning and the percentage of a Draw is 30%"<<endl;
    cout<<"3.d5 e6  4.Nc3 exd5 5.cxd5 Bd6"<<endl;
    cout<<"This leads to the Benoni Defense Snake Variation"<<endl;
    cout<<"In the Snake Variation, White has 38% chance of winning and Black has 33% chance of winning and the percentage of a Draw is 29%"<<endl;
    cout<<"3.d5 b5"<<endl;
    cout<<"This leads to the Benko Gambit Variation"<<endl;
    cout<<"In the Benko Gambit Variation, White has 40% chance of winning and Black has 26% chance of winning and the percentage of a Draw is 34%"<<endl;
    cout<<"3.d5 b5 4.e4"<<endl;
    cout<<"This leads to the Benko Gambit Declined Hjorring Countergambit Variation"<<endl;
    cout<<"In the Hjorring Countergambit Variation, White has 29% chance of winning and Black has 47% chance of winning and the percentage of a Draw is 24%"<<endl;
    cout<<"3.d5 b5 4.f3"<<endl;
    cout<<"This leads to the Benko Gambit Declined Pseudo Samisch Variation"<<endl;
    cout<<"In the Pseudo Samisch Variation, White has 29% chance of winning and Black has 43% chance of winning and the percentage of a Draw is 28%"<<endl;
    cout<<"3.d5 b5 4.a4"<<endl;
    cout<<"This leads to the Benko Gambit Declined Sosonko Variation"<<endl;
    cout<<"In the Sosonko Variation, White has 37% chance of winning and Black has 32% chance of winning and the percentage of a Draw is 31%"<<endl;
    cout<<"3.d5 b5 4.cxb5 a6"<<endl;
    cout<<"This leads to the Benko Gambit Accepted Variation"<<endl;
    cout<<"In the Accepted Variation, White has 39% chance of winning and Black has 26% chance of winning and the percentage of a Draw is 35%"<<endl;
    cout<<"3.d5 b5 4.cxb5 a6 5.b6"<<endl;
    cout<<"This leads to the Benko Gambit Accepted Pawn Return Variation"<<endl;
    cout<<"In the Pawn Return Variation, White has 39% chance of winning and Black has 30% chance of winning and the percentage of a Draw is 31%"<<endl;
    cout<<"3.d5 b5 4.cxb5 a6 5.f3"<<endl;
    cout<<"This leads to the Benko Gambit Accepted Dlugy Variation"<<endl;
    cout<<"In the Dlugy Variation, White has 37% chance of winning and Black has 33% chance of winning and the percentage of a Draw is 30%"<<endl;
    cout<<"3.d5 b5 4.cxb5 a6 5.Nc3"<<endl;
    cout<<"This leads to the Benko Gambit Accepted Zaitsev Variation"<<endl;
    cout<<"In the Zaitsev Variation, White has 34% chance of winning and Black has 43% chance of winning and the percentage of a Draw is 23%"<<endl;
}

void showcatalanvariations(){
    cout<<"This is a game of Catalan Opening"<<endl;
    cout<<"In the Catalan Opening, White has 29% chance of winning and Black has 21% chance of winning and the percentage of a Draw is 50%"<<endl;
    cout<<"Most Common further continuations of the game are as follows"<<endl;
    cout<<"3.g3 e5"<<endl;
    cout<<"This leads to the Catalan Opening Hungarian Gambit Variation"<<endl;
    cout<<"In the Hungarian Gambit Variation, White has 54% chance of winning and Black has 8% chance of winning and the percentage of a Draw is 38%"<<endl;
    cout<<"3.g3 d5 4.Bg2 dxc4 5.Nf3 Be7"<<endl;
    cout<<"This leads to the Catalan Opening Classical Variation"<<endl;
    cout<<"In the Classical Variation, White has 35% chance of winning and Black has 13% chance of winning and the percentage of a Draw is 52%"<<endl;
    cout<<"3.g3 d5 4.Bg2"<<endl;
    cout<<"This leads to the Catalan Opening Closed Variation"<<endl;
    cout<<"In the Closed Variation, White has 29% chance of winning and Black has 18% chance of winning and the percentage of a Draw is 53%"<<endl;
    cout<<"3.g3 d5 4.Bg2 dxc4 5.Nf3"<<endl;
    cout<<"This leads to the Catalan Opening Open Defense Variation"<<endl;
    cout<<"In the Open Defense Variation, White has 29% chance of winning and Black has 19% chance of winning and the percentage of a Draw is 52%"<<endl;
}

void showretivariations(){
    cout<<"This is a game of Reti Opening"<<endl;
    cout<<"In the Reti Opening, White has 34% chance of winning and Black has 22% chance of winning and the percentage of a Draw is 44%"<<endl;
    cout<<"Most Common further continuations of the game are as follows"<<endl;
    cout<<"1.Nf3 h6"<<endl;
    cout<<"This leads to the Reti Opening, Basman Defense Variation"<<endl;
    cout<<"In the Basman Defense Variation, White has 44% chance of winning and Black has 28% chance of winning and the percentage of a Draw is 28%"<<endl;
    cout<<"1.Nf3 c6"<<endl;
    cout<<"This leads to the Reti Opening Slav Invitation Variation"<<endl;
    cout<<"In the Slav Invitation Variation, White has 33% chance of winning and Black has 22% chance of winning and the percentage of a Draw is 45%"<<endl;
    cout<<"1.Nf3 b5"<<endl;
    cout<<"This leads to the Reti Opening Polish Defense Variation"<<endl;
    cout<<"In the Polish Defense Variation, White has 38% chance of winning and Black has 26% chance of winning and the percentage of a Draw is 36%"<<endl;
    cout<<"1.Nf3 b6"<<endl;
    cout<<"This leads to the Reti Opening Queenside Fianchetto Variation"<<endl;
    cout<<"In the Queenside Fianchetto Variation, White has 34% chance of winning and Black has 27% chance of winning and the percentage of a Draw is 39%"<<endl;
    cout<<"1.Nf3 Nc6"<<endl;
    cout<<"This leads to the Reti Opening Black Mustang Defense Variation"<<endl;
    cout<<"In the Black Mustang Defense, White has 38% chance of winning and Black has 23% chance of winning and the percentage of a Draw is 39%"<<endl;
    cout<<"1.Nf3 e6"<<endl;
    cout<<"This leads to the Reti Opening Queen's Gambit Invitation Variation"<<endl;
    cout<<"In the Queen's Gambit Invitation Variation, White has 40% chance of winning and Black has 21% chance of winning and the percentage of a Draw is 39%"<<endl;
    cout<<"1.Nf3 d6"<<endl;
    cout<<"This leads to the Reti Opening Pirc Invitation Variation"<<endl;
    cout<<"In the Pirc Invitation Variation, White has 36% chance of winning and Black has 27% chance of winning and the percentage of a Draw is 37%"<<endl;
    cout<<"1.Nf3 f5"<<endl;
    cout<<"This leads to the Reti Opening Dutch Variation"<<endl;
    cout<<"In the Dutch Variation, White has 40% chance of winning and Black has 23% chance of winning and the percentage of a Draw is 37%"<<endl;
    cout<<"1.Nf3 g6"<<endl;
    cout<<"This leads to the Reti Opening Kingside Fianchetto Variation"<<endl;
    cout<<"In the Kingside Fianchetto Variation, White has 34% chance of winning and Black has 28% chance of winning and the percentage of a Draw is 38%"<<endl;
    cout<<"1.Nf3 c5"<<endl;
    cout<<"This leads to the Reti Opening Sicilian Invitation Variation"<<endl;
    cout<<"In the Sicilian Invitation Variation, White has 32% chance of winning and Black has 25% chance of winning and the percentage of a Draw is 43%"<<endl;
}

void showenglishvariations(){
    cout<<"This is an English game"<<endl;
    cout<<"In the English Opening, White has 34% chance of winning and Black has 23% chance of winning and the percentage of a Draw is 43%"<<endl;
    cout<<"Most Common further continuations of the game are as follows"<<endl;
    cout<<"1.c4 d5"<<endl;
    cout<<"This leads to the English Opening Anglo-Scandinavian Defense Variation"<<endl;
    cout<<"In the Anglo-Scandinavian Variation, White has 44% chance of winning and Black has 12% chance of winning and the percentage of a Draw is 44%"<<endl;
    cout<<"1.c4 Nc6"<<endl;
    cout<<"This leads to the English Opening Anglo-Lithuanian Variation"<<endl;
    cout<<"In the Anglo-Lithuanian Variation, White has 42% chance of winning and Black has 26% chance of winning and the percentage of a Draw is 32%"<<endl;
    cout<<"1.c4 f5"<<endl;
    cout<<"This leads to the English Opening Anglo-Dutch Defense Variation"<<endl;
    cout<<"In the Anglo-Dutch Defense Variation, White has 38% chance of winning and Black has 25% chance of winning and the percentage of a Draw is 37%"<<endl;
    cout<<"1.c4 c6"<<endl;
    cout<<"This leads to English Opening Caro-Kann Defense Variation"<<endl;
    cout<<"In the Caro-Kann Defense Variation, White has 35% chance of winning and Black has 20% chance of winning and the percentage of a Draw is 45%"<<endl;
    cout<<"1.c4 g6"<<endl;
    cout<<"This leads to the English Opening Great Snake Variation"<<endl;
    cout<<"In the Great Snake Variation, White has 33% chance of winning and Black has 28% chance of winning and the percentage of a Draw is 39%"<<endl;
    cout<<"1.c4 c5"<<endl;
    cout<<"This leads to the English Opening Symmetrical Variation"<<endl;
    cout<<"In the Symmetrical Variation, White has 33% chance of winning and Black has 21% chance of winning and the percentage of a Draw is 46%"<<endl;
    cout<<"1.c4 e6"<<endl;
    cout<<"This leads to the ENglish Opening Agincourt Defense Variation"<<endl;
    cout<<"In the Agincourt Defense Variation, White has 35% chance of winning and Black has 22% chance of winning and the percentage of a Draw is 43%"<<endl;
    cout<<"1.c4 e5"<<endl;
    cout<<"This leads to the English Opening King's English Variation"<<endl;
    cout<<"In the King's English Variation, White has 32% chance of winning and Black has 25% chance of winning and the percentage of a Draw is 43%"<<endl;
    cout<<"1.c4 Nf6"<<endl;
    cout<<"This leads to the English Opening Anglo-Indian Defense Variation"<<endl;
    cout<<"In the Anglo-Indian Defense Variation, White has 36% chance of winning and Black has 22% chance of winning and the percentage of a Draw is 42%"<<endl;
}

void showbirdvariations(){
    cout<<"This is a game of Bird Opening"<<endl;
    cout<<"In the Bird Opening, White has 29% chance of winning and Black has 36% chance of winning and the percentage of a Draw is 35%"<<endl;
    cout<<"Most Common further continuations of the game are as follows"<<endl;
    cout<<"1.f4 b5"<<endl;
    cout<<"This leads to the Bird Opening Myers Defense Variation"<<endl;
    cout<<"In the Myers Defense Variation,  White has 45% chance of winning and Black has 30% chance of winning and the percentage of a Draw is 25%"<<endl;
    cout<<"1.f4 Nh6"<<endl;
    cout<<"This leads to the Bird Opening Horsefly Defense Variation"<<endl;
    cout<<"In the Horsefly Defense Variation, White has 35% chance of winning and Black has 35% chance of winning and the percentage of a Draw is 30%"<<endl;
    cout<<"1.f4 e5"<<endl;
    cout<<"This leads to the Bird Opening From's Gambit Variation"<<endl;
    cout<<"In the From's Gambit Variation, White has 39% chance of winning and Black has 29% chance of winning and the percentage of a Draw is 32%"<<endl;
    cout<<"1.f4 d5"<<endl;
    cout<<"This leads to the Bird Opening Dutch Variation"<<endl;
    cout<<"In the Dutch Variation, White has 27% chance of winning and Black has 36% chance of winning and the percentage of a Draw is 37%"<<endl;
}

void showkingsindianattackvariations(){
    cout<<"This is a game of King's Indian Attack"<<endl;
    cout<<"In the King's Indian Attack Opening, White has 34% chance of winning and Black has 23% chance of winning and the percentage of a Draw is 43%"<<endl;
    cout<<"Most Common further continuations of the game are as follows"<<endl;
    cout<<"2.g3 c5"<<endl;
    cout<<"This leads to the King's Indian Attack Sicilian Variation"<<endl;
    cout<<"In the Sicilian Variation, White has 36% chance of winning and Black has 22% chance of winning and the percentage of a Draw is 42%"<<endl;
    cout<<"2.g3 g6"<<endl;
    cout<<"This leads to the King's Indian Attack Double Fianchetto Variation"<<endl;
    cout<<"In the Double Fianchetto Variation, White has 29% chance of winning and Black has 27% chance of winning and the percentage of a Draw is 44%"<<endl;
    cout<<"2.g3 Bg4"<<endl;
    cout<<"This leads to the King's Indian Attack Keres Variation"<<endl;
    cout<<"In the Keres Variation, White has 33% chance of winning and Black has 25% chance of winning and the percentage of a Draw is 42%"<<endl;
}

void showhungarianvariations(){
    cout<<"This is a game of Hungarian Opening"<<endl;
    cout<<"In the Hungarian Opening, White has 36% chance of winning and Black has 25% chance of winning and the percentage of a Draw is 39%"<<endl;
    cout<<"Most Common further continuations of the game are as follows"<<endl;
    cout<<"1.g3 Nf6"<<endl;
    cout<<"This leads to the Hungarian Opening Indian Defense Variation"<<endl;
    cout<<"In the Indian Defense Variation, White has 41% chance of winning and Black has 21% chance of winning and the percentage of a Draw is 38%"<<endl;
    cout<<"1.g3 g6"<<endl;
    cout<<"This leads to the Hungarian Opening Symmetrical Variation"<<endl;
    cout<<"In the Symmetrical Variation, White has 36% chance of winning and Black has 24% chance of winning and the percentage of a Draw is 40%"<<endl;
    cout<<"1.g3 c5"<<endl;
    cout<<"This leads to the Hungarian Opening Sicilian Variation"<<endl;
    cout<<"In the Sicilian Variation, White has 34% chance of winning and Black has 26% chance of winning and the percentage of a Draw is 40%"<<endl;
    cout<<"1.g3 f5"<<endl;
    cout<<"This leads to the Hungarian Opening Dutch Defense Variation"<<endl;
    cout<<"In the Dutch Defense Variation, White has 41% chance of winning and Black has 26% chance of winning and the percentage of a Draw is 33%"<<endl;
}

void shownimzolarsenvariations(){
    cout<<"This is a game of Nimzowitsch-Larsen Attack"<<endl;
    cout<<"In the Nimzowitsch-Larsen Attack, White has 34% chance of winning and Black has 30% chance of winning and the percentage of a Draw is 36%"<<endl;
    cout<<"Most Common further continuations of the game are as follows"<<endl;
    cout<<"1.b3 e5"<<endl;
    cout<<"This leads to the Nimzowitsch-Larsen Attack Modern Variation"<<endl;
    cout<<"In the Modern Variation, White has 33% chance of winning and Black has 31% chance of winning and the percentage of a Draw is 36%"<<endl;
    cout<<"1.b3 d5"<<endl;
    cout<<"This leads to the Nimzowitsch-Larsen Attack Classical Variation"<<endl;
    cout<<"In the Classical Variation, White has 33% chance of winning and Black has 31% chance of winning and the percentage of a Draw is 36%"<<endl;
    cout<<"1.b3 Nf6"<<endl;
    cout<<"This leads to the Nimzowitsch-Larsen Attack Indian Variation"<<endl;
    cout<<"In the Indian Variation, White has 35% chance of winning and Black has 28% chance of winning and the percentage of a Draw is 37%"<<endl;
    cout<<"1.b3 c5"<<endl;
    cout<<"This leads to the Nimzowitsch-Larsen Attack English Variation"<<endl;
    cout<<"In the English Variation, White has 36% chance of winning and Black has 31% chance of winning and the percentage of a Draw is 33%"<<endl;
    cout<<"1.b3 b6"<<endl;
    cout<<"This leads to the Nimzowitsch-Larsen Attack Symmetrical Variation"<<endl;
    cout<<"In the Symmetrical Variation, White has 30% chance of winning and Black has 28% chance of winning and the percentage of a Draw is 42%"<<endl;
    cout<<"1.b3 f5"<<endl;
    cout<<"This leads to the Nimzowitsch-Larsen Attack Dutch Variation"<<endl;
    cout<<"In the Dutch Variation, White has 39% chance of winning and Black has 24% chance of winning and the percentage of a Draw is 37%"<<endl;
    cout<<"1.b3 b5"<<endl;
    cout<<"This leads to the Nimzowitsch-Larsen Attack Polish Variation"<<endl;
    cout<<"In the Polish Variation, White has 56% chance of winning and Black has 19% chance of winning and the percentage of a Draw is 25%"<<endl;
}

void checkforopenings(vector<string> &game){
    if(checkforsiciliandefense(game)){
        showsicilianvariations();
    }
    if(checkforfrenchdefense(game)){
        showfrenchvariations();
    }
    if(checkforruylopez(game)){
        showruylopezvariations();
    }
    if(checkforcarokann(game)){
        showcarokannvariations();
    }
    if(checkforitalian(game)){
        showitalianvariations();
    }
    if(checkforscandinavian(game)){
        showscandinavianvariations();
    }
    if(checkforpircdefense(game)){
        showpircdefensevariations();
    }
    if(checkforalekhinedefense(game)){
        showalekhinedefensevariations();
    }
    if(checkforkingsgambit(game)){
        showkingsgambitvariations();
    }
    if(checkforscotchgame(game)){
        showscotchgamevariations();
    }
    if(checkforvienna(game)){
        showviennavariations();
    }
    if(checkforqueensgambit(game)){
        showqueensgambitvariations();
    }
    if(checkforkingsindiandefense(game)){
        showkingsindiandefensevariations();
    }
    if(checkfornimzoindian(game)){
        shownimzoindianvariations();
    }
    if(checkforqueensindian(game)){
        showqueensindianvariations();
    }
    if(checkforbogoindian(game)){
        showbogoindianvariations();
    }
    if(checkfordutchdefense(game)){
        showdutchdefensevariations();
    }
    if(checkfortrompowskyattack(game)){
        showtrompowskyattackvariations();
    }
    if(checkforlondon(game)){
        showlondonvariations();
    }
    if(checkforbenonidefense(game)){
        showbenonidefensevariations();
    }
    if(checkforcatalan(game)){
        showcatalanvariations();
    }
    if(checkforreti(game)){
        showretivariations();
    }
    if(checkforenglish(game)){
        showenglishvariations();
    }
    if(checkforbird(game)){
        showbirdvariations();
    }
    if(checkforkingsindianattack(game)){
        showkingsindianattackvariations();
    }
    if(checkforhungarian(game)){
        showhungarianvariations();
    }
    if(checkfornimzolarsen(game)){
        shownimzolarsenvariations();
    }
}

bool checkformoves(vector<string> &game){
    vector<string> opening;
    opening.push_back("BR BN BB BQ BK BB BN BR");
    opening.push_back("BP BP BP BP BP BP BP BP");
    opening.push_back("11 11 11 11 11 11 11 11");
    opening.push_back("11 11 11 11 11 11 11 11");
    opening.push_back("11 11 11 11 11 11 11 11");
    opening.push_back("11 11 11 11 11 11 11 11");
    opening.push_back("WP WP WP WP WP WP WP WP");
    opening.push_back("WR WN WB WQ WK WB WN WR");
    for(int i=0;i<game.size();i++){
        if(game[i]!=opening[i]){
            return true;
        }
    }
    return false;
}

int main(){
    unordered_set<string> hash_char;
    createhash(hash_char);
    vector<string> game;
    int row=8;
    bool isittrue;
    showrules();
    showopeningposition();
    cout<<"Make the opening moves and enter the opening position to be analyzed: "<<endl;
    getposition(game,row);
    isittrue=checkformultiplespaces(game);
    if(isittrue){
        cout<<"There are multiple spaces in the given position"<<endl;
        cout<<"Please enter the position without multiple spcaing"<<endl;
    }
    if(!isittrue){
        checkpieces(game,hash_char);
    }
    if(checkformoves(game)==false){
        cout<<"No opening Moves have been made"<<endl;
    }
    if(checkformoves(game)){
        checkforopenings(game);
    }
    cout<<"If there is no analysis obtained, the given chess position is either in the middle game or an endgame position"<<endl;
    cout<<"Enter an opening postion to be analyzed"<<endl;
    cout<<"Thank You for using Opening Analyzer"<<endl;
}