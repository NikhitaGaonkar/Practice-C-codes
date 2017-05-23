int bulbSwitch(int n) {
    
    if(n<=0)
    {
        return 0;
    }
    if(n<=2)
    {
        return 1;
    }
    int count=0;
    int *arr = (int*)calloc(n, sizeof(int));
    for(int i=0; i<n; i++)
      arr[i]=1;
      
    int j=0;
    //turn off every second bulb
    while(j<n)
    {
        j  = (j*2)+1;
        arr[j] =0;
    }
     
    //start from third round
   // j=0;
    for(int i =3; i<=n; i++)
    {
        j =i;
       // while(j<=n)
        {
          printf("%d %d %d \n", n, j, arr[j-1]);
          arr[j-1] = !arr[j-1];   
          //j+= i;
        }
        printf("---\n");
    }
 
    for(int k=0; k<n; k++)
    {
         printf("%d \n", arr[k]);
        if(arr[k]==1)
          count ++;
    }
  //  printf("\n%d", count);

    return count;
}
