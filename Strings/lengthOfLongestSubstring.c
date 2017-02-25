int lengthOfLongestSubstring(char* str) {
    int map[256];
    for(int k=0; k<256; k++)
      map[k] = -1;
      
    int len = strlen(str);
    int len_so_far = 0, max_len =0, start=0;
    
    for(int i=0; i<len; i++)
    {
       //set start to position one higher than the previous position of repeating
	   //character only if it is not part od the current substring under consideration 
       if(map[str[i]] != -1 && start <= map[str[i]])
         start = map[str[i]] +1;
        
       map[str[i]] = i;
       len_so_far = i-start+1;
       if(len_so_far>max_len)
         max_len = len_so_far;
    }
    return max_len;
}


#if 0
int lengthOfLongestSubstring(char* s) {
   
   int len = strlen(s);
 
   if(len==1 || len == 0)
     return len;
     
   int curr_len = 1;
   int max_len = 1;
   int prev_pos = 0;
   
   //array of 256 to keep track of visited chars 
   int *visited = (int*)malloc(sizeof(int)*256);
   
   //init the visited array
   for(int i =0; i<256; i++)
     visited[i]= -1;
   
   //visit 1st char 
   visited[s[0]] = 0;
     
   for(int i =1; i<len; i++)
   {
       prev_pos = visited[s[i]];
       
       //check if not visited atall or if visited but not part of the string under consideration
       if(prev_pos == -1 || i-curr_len > prev_pos)
         curr_len++;
    
       else
       {
           if(curr_len>max_len)
             max_len = curr_len;
           
           //adjusting the len by excluding the last visted and inculing the new 
           //to find new max len
           curr_len = i-prev_pos;
       }
       
       visited[s[i]] = i;
   }
   
   if(curr_len >max_len)
     max_len = curr_len;
     
   free(visited);
   return max_len;
}
#edif

