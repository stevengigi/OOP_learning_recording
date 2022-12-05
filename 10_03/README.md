####  OOP 10/03

- MathVector
    - if  MathVector data will be changed , we need write member function(write in MathVector)
    - otherwise we just write function

- copy constructor(自己做複製動作)
    - 被觸發的時刻 : dot(v1,v2) -> dot(MathVector v3,const MathVector &v2) v3 做 copy constructor
    - 物件被輸入到副程式時會使用到(加上'&')，可避免做copy construct 直接 pass by reference(&v2 : avoid copy)
    - const MathVector &input <- 避免做copy的動作('&')，且內部資料不能做更改
    - this 是指 dot(MathVector v3)本身自己的物件，且去複製主程式的v1.

- pass by value(i will be not changed)
``` c=
void func(int i){
    i=10;
}

int main(){
    int i=0;
    func(i);
}
```
- pass by reference(copy will be not occurred)
    - 記憶體空間使用外面輸入的(就不會在做copy 新增一個記憶體的空間，沿用傳進來的物件)
    - pass by reference('&'): avoid copy
``` c=
MathVector(const MathVector &input){ // copy constructor
        this->_dim = input._dim;
        this->_arr= new double[this->_dim];
        for(int i=0;i<_dim;i++){
            this->_arr[i]=input._arr[i];
        }
    }
```

- const
    - can't change value