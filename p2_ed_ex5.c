int isValid(char* s) {
    Stack* stack = createStack();
    
    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(stack, s[i]);
        } else {
            if(isEmpty(stack)) 
            return 0;
            
            char top = pop(stack);
            
            if(s[i] == ')' && top != '(') 
            return 0;
            if(s[i] == '}' && top != '{') 
            return 0;
            if(s[i] == ']' && top != '[') 
            return 0;
        }
    }
    
    int result = isEmpty(stack);
    freeStack(stack);
    return result;
}