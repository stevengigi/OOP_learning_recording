####  OOP 10/07

- MathVector operator overloading
    - operator= need to use return by reference('&')
    ``` c=
    MathVector& operator=(const MathVector &input){ //copy assignment,assignment operator overloading
            if(this!= &input) // this is a pointer(address)
            {                  // '&' address of operator
                init(input._dim,input._arr);
            }
            std::cout << "copy assignment" << std::endl;
            return *this;
        }
    ```
    - problem : memory leak (original data didn't delete)!!
