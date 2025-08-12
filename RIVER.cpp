#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>   
using namespace std;
template <class T>
class VecList{
private:
    T* arr; 
    int capacity; 
    int length; 

    void doubleListSize(){
        T* newArr = new T[2*capacity];
        for(int i=0;i<length;i++){
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = 2*capacity;
    }
public:
    VecList(){
        arr = new T[100];
        capacity = 100;
        length = 0;
    }
    VecList(T* a, int n){ 
        arr = new T[100+2*n];
        capacity = 100+2*n;
        length = n;
        for(int i=0;i<n;i++){
            arr[i] = a[i];
        }
    }
    ~VecList(){
        delete[] arr;
    }
    int getLength(){
        return length;
    }
    bool isEmpty(){
        return length==0;
    }
    void insertEleAtPos(int i, T x){
        if(i<0 || i > length){
            throw "Illegal position";
        }
        if(capacity == length){
            doubleListSize();
        }
        for(int j=length-1;j>=i;j--){ 
            arr[j+1] = arr[j];
        }
        arr[i] = x;
        length++;
    }
    T deleteEleAtPos(int i){
        if(i < 0 || i >= length){
            throw "Illegal position";
        }
        T tmp = arr[i];
        for(int j=i+1;j<length;j++){
            arr[j-1] = arr[j];
        }
        length--;
        return tmp;
    }
    void setEleAtPos(int i, T x){
        if(i < 0 || i >= length){
            throw "Illegal position";
        }
        arr[i] = x;
    }
    T getEleAtPos(int i){
        if(i < 0 || i >= length){
            throw "Illegal position";
        }
        return arr[i];
    }
    int locateEle(T x){ 
        int k = 0;
        while(k < length){
            if(arr[k] == x) return k;
            else k++;
        }
        return -1;
    }
    void printList(){
        for(int i=0;i<length;i++){
            cout << arr[i] << " ";
        }
    }
};

using namespace std; 
bool cout_yn = false;
template <class T>
struct DNode{
    T data;
    DNode<T>* next;
};
struct place_logic
{
    int place;
    int logic;      
};
template <class T>
class LinkList{
    private:
        int length;
        DNode<T>* head;
    public:
        LinkList(){
            head = new DNode<T>;
            head->next = NULL;
            length = 0;
        }
        LinkList(T* a, int n){
            head = new DNode<T>;
            head->next = NULL;
            for(int i=n-1;i>=0;i--){
                DNode<T> *tmpNode = new DNode<T>;
                tmpNode->next = head->next;
                tmpNode->data = a[i];
                head->next = tmpNode;
            }
            length = n;
        } 
        LinkList(const LinkList<T>& other) {
            head = new DNode<T>;
            head->next = nullptr;
            length = 0;

            DNode<T>* current = other.head->next;
            DNode<T>* tail = head;

            while (current != nullptr) {
                DNode<T>* newNode = new DNode<T>;
                newNode->data = current->data;  
                newNode->next = nullptr;
                tail->next = newNode;
                tail = newNode;
                length++;
                current = current->next;
            }
        }
        ~LinkList(){
            while(head!=NULL){
                DNode<T>* tmpNode = head;
                head = head->next;
                delete tmpNode;
            }
        }
        int getLength(){
            return length;
        }
        bool isEmpty(){
            return length==0;
        }
        void insertEleAtPos(int i, T x){
            if(i < 0 || i > length)
                throw "Bad position";
            DNode<T>* tmpNode = head;
            for(int j=0;j<i;j++){
                tmpNode = tmpNode->next;
            }
            DNode<T>* newNode = new DNode<T>;
            newNode->data = x;
            newNode->next = tmpNode->next;
            tmpNode->next = newNode;
            length++;
        }
        void insertEleAtPos_struct(int i, const LinkList<int>& x){ 
            if(i < 0 || i > length)
                throw "Bad position";
            DNode<T>* tmpNode = head;
            for(int j=0;j<i;j++){
                tmpNode = tmpNode->next;
            }
            DNode<T>* newNode = new DNode<T>;
            newNode->data = x;
            newNode->next = tmpNode->next;
            tmpNode->next = newNode;
            length++;
        }
        T deleteEleAtPos(int i){
            if(i < 0 || i >= length)
                throw "Bad position";
            DNode<T>* tmpNode = head;
            for(int j=0;j<i;j++){
                tmpNode = tmpNode->next;
            }
            DNode<T>* delNode = tmpNode->next;
            tmpNode->next = delNode->next;
            T tmp = delNode->data;
            delete delNode;
            length--;
            return tmp;
        }
        void setEleAtPos(int i, T x){
            if(i < 0 || i >= length)
                throw "Bad position";
            DNode<T>* tmpNode = head;
            for(int j=0;j<=i;j++){
                tmpNode = tmpNode->next;
            }
            tmpNode->data = x;
        }
        void setEleAtPos_struct(int i, const LinkList<place_logic>& x){
            if(i < 0 || i >= length)
                throw "Bad position";
            DNode<T>* tmpNode = head;
            for(int j=0;j<=i;j++){
                tmpNode = tmpNode->next;
            }
            tmpNode->data = x;
        }
        
        T getEleAtPos(int i){
            if(i < 0 || i >= length)
                throw "Bad position";
            DNode<T>* tmpNode = head;
            for(int j=0;j<=i;j++){
                tmpNode = tmpNode->next;
            }
            return tmpNode->data;
        }
        int locateEle(T x){
            DNode<T>* tmpNode = head->next;
            int count = 0;
            while(tmpNode!=NULL){
                if(tmpNode->data == x) return count;
                tmpNode = tmpNode->next;
                count++;
            }
            return -1;
        }
        void printList(){
            DNode<T>* tmpNode = head->next;
            while(tmpNode!=NULL){
                cout << tmpNode->data << " ";
                tmpNode = tmpNode->next;
            }
        }
};


struct row_data{
    int row;
    int data;
};
LinkList<int> *f(int num_variable,place_logic *B,LinkList<int>**variable_places,int equation,VecList<int>* river_simple_col){         
    LinkList<int> *A = new LinkList<int>;
    for(int i = 0;i<num_variable;i++){
        A->insertEleAtPos(i,0);
    }
    place_logic mid;
    row_data mid2;
    for(int i = 0;i<3;i++){
        int num = 0;
        int place = 0;
        int logic = 0;
        cin>>num;
        if(num > 0){
            logic = 1;
            place = num;
        }
        else{
            logic = -1;
            place = (-num);
        }
        mid.logic = logic;
        mid.place = place - 1;
  
        river_simple_col[mid.place].insertEleAtPos(river_simple_col[mid.place].getLength(),logic*equation);

        variable_places[mid.place]->insertEleAtPos(variable_places[mid.place]->getLength(),equation);
        

        A->setEleAtPos(place-1,logic);
        B[i] = mid;
    }
    return A;
}
int get_length_of_river(LinkList<LinkList<int> > *river, int x_i, int* delete_success, bool update_delete_success,LinkList<int> **variable_places,VecList<int> * river_simple_col) {
    int cnt = 0;
    int cnt_N = 0;
    int len = river->getLength();
    if(variable_places!=nullptr){   
        if(variable_places[x_i]->getLength()==1) cnt = 999;
        int all_v = river->getEleAtPos(0).getLength();
        for(int i = 0;i < all_v;i++){
            
            if(variable_places != nullptr && variable_places[i]->getLength()==1) {
                
                delete_success[variable_places[i]->getEleAtPos(0)] = 1;

            }
        }
    }
    int len2 = river_simple_col[x_i].getLength();
    int tmp_row;
    for(int i = 0; i < len2; i++) {
        tmp_row = river_simple_col[x_i].getEleAtPos(i);
        
        if(delete_success != nullptr && delete_success[abs(tmp_row)] == 1) {
            continue;  
        }
        
        if(tmp_row > 0) cnt++;          
        else cnt_N--;
    }

    int logic = (cnt > abs(cnt_N)) ? cnt : -abs(cnt_N);

    if(update_delete_success && delete_success != nullptr){
        if(cnt > abs(cnt_N)){
            for(int i = 0; i < len; i++){
                if(delete_success[i] == 1) continue;
                if(river->getEleAtPos(i).getEleAtPos(x_i) > 0) {        
                    delete_success[i] = 1;
                }
            }
        } 
        else {
            for(int i = 0; i < len; i++){
                if(delete_success[i] == 1) continue;
                if(river->getEleAtPos(i).getEleAtPos(x_i) < 0) {        
                    delete_success[i] = 1;
                }
            }
        }

        
        if(cout_yn){cout << "delete:";
        for(int i = 0; i < len; i++){
            cout << " " << delete_success[i];
        }
        cout << endl;
        }
    }

    return logic;
}


// void printriver(LinkList<LinkList<int> > *river,int num_variable,int num_place){
    // cout<<"RIVER!"<<endl;
    // cout<<"-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-"<<endl;
    // cout << "variable"  << " : ";
    // cout << "( ";
    // for(int i = 0;i<num_variable;i++){
    //     cout<< "x"<<i + 1;
    //     if(i!=num_variable-1) cout<<"\t";
    // }
    // cout<<"\t)"<<endl;
//     for (int i = 0; i < num_place; i++) {
//         cout << "place_" << i << "  : ";
//         cout << "( ";
//         for(int o = 0;o < num_variable;o++){
//             cout<< river->getEleAtPos(i).getEleAtPos(o);
//             if(o!=num_variable-1) cout<<"\t";
//         }
//         cout<<"\t)";
//         cout<<endl;

//     }
//     cout << "\nlength  "  << " : ";
//     cout << "( ";
//     for(int i = 0;i<num_variable;i++){
//         cout << get_length_of_river(river, i, nullptr, false,nullptr);
// ;
//         if(i!=num_variable-1) cout<<"\t";
//     }
//     cout<<"\t)"<<endl;
//     cout<<"-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-"<<endl;
//     return ;
    
// }

bool balance(LinkList<LinkList<int> > *river, int*answer,place_logic**river_simple,int*changed,LinkList<int>**variable_places,LinkList<int>*total_need){
 
    bool balance = false;
    bool notall = bool(changed[0] != -1);
    bool all_bad = false;
    if(!total_need->isEmpty()){                                     //优先查找need之中 
        for(int i = 0;i<total_need->getLength();i++){
            balance = false;
            for(int j = 0;j<3;j++){
                place_logic mid = river_simple[total_need->getEleAtPos(i)][j];
                if(mid.logic*answer[mid.place]==1) {
                    balance = true;
                }
            }
            if(balance) {
                if(total_need->getLength()){
                total_need->deleteEleAtPos(i);
                i--;
                }
            }
            if(!balance) {
                if(cout_yn) {
                            for(int o = 0;o<river->getEleAtPos(i).getLength();o++){
                                if(river->getEleAtPos(i).getEleAtPos(o)) cout<<"river[i][o] = "<<river->getEleAtPos(i).getEleAtPos(o) <<"\nanswer = "<<answer[o]<<endl;;
                            } 
                            cout<<"[ ";
                            for(int j = 0;j<river->getEleAtPos(0).getLength();j++){
                                cout<<answer[j];
                                if (j<river->getEleAtPos(0).getLength()-1) cout<<" , ";
                            }
                            cout<<" ]"<<endl;
                            cout<<"False ! \t---------"<<" cuz place_"<<total_need->getEleAtPos(i)<<endl;

                            cout<<"- - - - - - - - - - - - - - -"<<endl;
                }
                all_bad = true;
            }
        }              
        if(all_bad) return false;
        
    }
     
        
        for (int i = 0;i<river->getLength();i++){

            balance = false;
            int false_place = 0;
            place_logic mid;
            for(int o = 0;o<3;o++){
                mid = river_simple[i][o];
                if(mid.logic * answer[mid.place]==1){
                    balance = true;
                } 
            }
            if(!balance) {
                false_place = i;
                total_need->insertEleAtPos(total_need->getLength(),i);
                if(cout_yn) {
                    for(int o = 0;o<river->getEleAtPos(i).getLength();o++){
                        if(river->getEleAtPos(i).getEleAtPos(o)) cout<<"river[i][o] = "<<river->getEleAtPos(i).getEleAtPos(o) <<"\nanswer = "<<answer[o]<<endl;;
                    }
                    cout<<"[ ";
                    for(int j = 0;j<river->getEleAtPos(0).getLength();j++){
                        cout<<answer[j];
                        if (j<river->getEleAtPos(0).getLength()-1) cout<<" , ";
                    }
                    cout<<" ]"<<endl;
                    cout<<"False ! \t---------"<<" cuz place_"<<false_place<<endl;

                    cout<<"- - - - - - - - - - - - - - -"<<endl;
                }
                all_bad = true;
                
            }
            
            
            
        }
        if(all_bad)return false; 
    for(int j = 0;j<river->getEleAtPos(0).getLength();j++){
        if(answer[j]==1) cout<<answer[j];
        if(answer[j]==-1) cout<<answer[j]+1;
        if (j<river->getEleAtPos(0).getLength()-1) cout<<" ";
    } 
    return true;
}


place_logic* length_List(LinkList<LinkList<int> > *river,LinkList<int> **variable_places,VecList<int> * river_simple_col) {
    int len = river->getLength();
    int num_x = river->getEleAtPos(0).getLength();
    place_logic* length_list = new place_logic[num_x];

    

    int* delete_success = new int[len];

    for(int i = 0; i < len; i++) delete_success[i] = 0;

    bool* variable_processed = new bool[num_x];
    for(int i = 0; i < num_x; i++) variable_processed[i] = false;

    for(int k = 0; k < num_x; k++) {
        int max_length = -1;
        int max_variable = -1;
        int max_logic = 0;
        
        // 找到未处理的变量中河流长度最长的变量
        for(int i = 0; i < num_x; i++) {
            if(variable_processed[i]) continue;
            int logic = get_length_of_river(river, i, delete_success, false,variable_places,river_simple_col); // 不更新 delete_success
            int length = abs(logic);
            
            if(length > max_length) {
                max_length = length;
                max_variable = i;
                max_logic = logic;
            }
        }
        
        if(max_variable == -1) break; // 所有变量都已处理

        // 标记该变量已处理
        variable_processed[max_variable] = true;

        // 记录变量的 place 和 logic
        length_list[k].place = max_variable;
        length_list[k].logic = max_logic;

        // 更新 delete_success 数组，删除对应的河流
        get_length_of_river(river, max_variable, delete_success, true,variable_places,river_simple_col); // 更新 delete_success
    }

    delete[] delete_success;
    delete[] variable_processed;
    return length_list;
}
int* setBinaryInArray(unsigned long long tms, int size, unsigned usefulVars, place_logic* lenth_river_list) {
    vector<int> change_(size, 0);

     

    for (int i = 0; i < usefulVars; i++) {
        int place = lenth_river_list[i].place;
        change_[place] = (tms >> i) & 1;
    }

    int* result = new int[size];
    for (int i = 0; i < size; ++i) {
        result[i] = change_[i];
    }

    return result;
}


int randomPick(LinkList<int>* total_need) {
    
    int length = total_need->getLength();
    if (length == 0) {
        std::cerr << "Error: total_need is empty!" << std::endl;
        return -1; // 或者其他错误处理
    }

    // 生成随机索引
    int randomIndex = std::rand() % length; // 随机索引
    return total_need->getEleAtPos(randomIndex); // 返回随机选择的元素
}

int* change_answer(int* answer, unsigned long long tms, int size, unsigned int usefulVars, place_logic *lenth_river_list,int*changed,LinkList<int> *total_need,place_logic ** river_simple){

    if(total_need->isEmpty()) return answer;
    int need = 0;
    int ran = randomPick(total_need);
    int place = 0;
    place_logic mid;

    int run = 0;
    if(!tms%203) {
        for(int i = 0;i<3;i++){
            mid = river_simple[ran][i];
            if(abs(mid.logic)>need) {
                need = abs(mid.logic);
                place = i;
            }
        }
        answer[rand() % size] *= -1;
        answer[lenth_river_list[tms%5].place] *= -1;
    }
    while(1){
        place = rand() % 3;
        
        run++;
         
        break;
    }
    

    answer[river_simple[ran][place].place] *= -1;
    if(cout_yn){
        cout<<"has changed: x_"<<river_simple[ran][place].place+1<<endl;
        cout<<"now answer: ";
        for(int i = 0;i<size;i++){
            cout<<answer[i]<<" ";
        }
        cout<<endl;
    }
    return answer;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - RIVER - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//
int main(){
     

    if (freopen("test_100_400.txt", "r", stdin) == NULL) {
        cout << "无法打开文件 test.txt" << endl;
        return 1;
    }
    int num_variable;   //变量个数
    int num_place;      //河流途径点总数 即式子个数
    int place,logic;
    cin>>num_variable>>num_place;
    LinkList<LinkList<int> > *river = new LinkList<LinkList<int> >;
    int *answer_try = new int[num_variable];

    LinkList<int> **variable_places = new LinkList<int>*[num_variable];

    VecList<int> river_simple_col[num_variable];

    place_logic ** river_simple = new place_logic*[num_place];
    for (int i = 0;i<num_variable;i++){
        variable_places[i] = new LinkList<int>();
    }
    for (int i = 0;i<num_place;i++){
        river_simple[i] = new place_logic[3];

        LinkList<int>* A = f(num_variable,river_simple[i],variable_places,i,river_simple_col);
 
        river->insertEleAtPos_struct(i, *A);
        
    }
    
     


    int test[5] = {-1,1,1,1,1};


    

    place_logic *lenth_river_list = length_List(river,variable_places,river_simple_col);  



    unsigned int usefulVars = 0;
    for(int i = 0; i < num_variable; i++) {
        
        int temp_place = lenth_river_list[i].place;        if (lenth_river_list[i].logic > 0) {
            answer_try[temp_place] = 1;
            usefulVars++;
        } else if (lenth_river_list[i].logic < 0) {
            answer_try[temp_place] = -1;
            usefulVars++;
        } else {
            answer_try[temp_place] = -1; 
        }
        if(variable_places[temp_place]->getLength()==1) {             
            answer_try[temp_place] = river->getEleAtPos(variable_places[temp_place]->getEleAtPos(0)).getEleAtPos(temp_place);

        }
    }





    int x_is_useless = 0; 
    int lenn = river->getEleAtPos(0).getLength();
    for(int i = 0;i<lenn;i++){
        if(lenth_river_list[i].logic==0) x_is_useless++;
    }
    /*    TEST ------------------------------------------------------TEST
    */
    unsigned long long tms = 0;
    // int total_attempts = pow(2, usefulVars);
    unsigned long int  total_attempts = 100000000000;
    int changed[num_variable];
    fill(changed, changed + num_variable, -1);

    LinkList<int> *total_need = new LinkList<int>();  //记录需要改的.   linklist结构使得增减极其容易！ 
    for(int i = 0;i<num_place;i++){
        bool balance_ = false;
        for(int j = 0;j<num_variable;j++){
            if(river->getEleAtPos(i).getEleAtPos(j) * answer_try[j] == 1) balance_ = true;
        }
        if (!balance_) {
            total_need->insertEleAtPos(total_need->getLength(),i);
        }
    }

    
    while(tms < total_attempts){

        int* modified_answer = change_answer(answer_try, tms, num_variable, usefulVars, lenth_river_list,changed,total_need,river_simple);
        
        if(balance(river, modified_answer,river_simple,changed,variable_places,total_need)){ 
            break;
        } 
        fill(changed, changed + num_variable, -1);
        tms++;
    }

    if(tms == total_attempts){
        cout << "\n\n\n\nThere is no answer!!\nThere is no answer!!\nThere is no answer!!" << endl;
    }

    return 0;   
}
//TODO: 1.也许要稀疏计算✅    2.已经流通的place不必再判断 考虑修改后的几个就好 （1 找到改了哪几个变量 2 找到变量x对应过的方程位置）✅ 3，方程内部化简 若1 2 3 和-1 -2 3 则第三位已经确定 4.单独元素（只含在一个place里）一定确定值✅
//              5.若长期需要修改一个元素，则直接修改对应位置涉及到的变量 ✅
//              现考虑更改算法，不使用占数量最小的优先修改，而是优先修改 错误+影响不大的（正负均衡，数量较多）✅