####  OOP 9/26

- learn how to use #ifndef
    - avoid too much file include same file , we need to use #ifndef at head file
    - can avoid error called redefinition


- learn copy when function be called(pass by value normally)
    - MathVector 包含 pointer ，再傳送到副程式時 compiler 會做 copy 的動作，但是 pointer(複製出來的)指到的 address 會跟主程式 MathVector 裡的 pointer 指到相同address，所以副程式執行完後 address 會被 free(destructor) ，主程式結束後，沒東西可以free(destructor)所以報error。

- pass by value example
``` c=

void func(int i){
    i=10;
}

int main(){
    int i=0;
    func(i);
}

```