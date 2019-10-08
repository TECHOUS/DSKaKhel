#include<stack>
void revStack(stack<int>& s1, stack<int>& s2) {
		     
         if(s1.size() <=1){return;
   }
   int lastelement=s1.top();
   
   s1.pop();
   
   revStack(s1,s2);
   
   while(!s1.Empty()){

        int p = s1.top();
        s1.pop();
        s2.push(p);
        }

s1.push(lastelement);

while(!s2.Empty()){

            int q = s2.top();
            s2.pop();
            s1.push(p);
          }
}
