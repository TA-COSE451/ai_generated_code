/*
This is my code

int main(){
   int N,i,radius,diameter,count =0;
   char str[20];
   char color[N][20];
   printf("Get the num : ");
   scanf("%d",&N);

   printf("Enter the mesage\n");
   for(i=0;i<N;i++){
      fgets(color[i],20,stdin);
   }
   for(i=0;i<N;i++){
      printf("%s",color[i]);
  }
  return 0;
}

Given inputs are:

N = 3
red 50,
50 green,
blue 50

Here the problem is fgets inside for loop gets executed only twice if N is 3. This problem doesn't arise if I comment the scanf statement. Can somebody explain me what is causing this problem and how it can be solved?
*/

int main() {
   int N,i,radius,diameter,count = 0;
   char str[20];
   
   printf("Get the num : ");
   scanf("%d",&N);
   getchar(); // Consume the newline character left in the input buffer after reading N

   char color[N][20];
   
   printf("Enter the message:\n");
   for(i = 0; i < N; i++){
      fgets(color[i], 20, stdin);
   }

   for(i = 0; i < N; i++){
      printf("%s", color[i]);
   }

   return 0;
}

/*
- Request:
Please fix the below C program.

- Code to fix:
int main(){
   int N,i,radius,diameter,count =0;
   char str[20];
   char color[N][20];
   printf("Get the num : ");
   scanf("%d",&N);

   printf("Enter the mesage\n");
   for(i=0;i<N;i++){
      fgets(color[i],20,stdin);
   }
   for(i=0;i<N;i++){
      printf("%s",color[i]);
  }
  return 0;
}

- Error:
Given inputs are:
N = 3
red 50,
50 green,
blue 50

Here the problem is fgets inside for loop gets executed only twice if N is 3. This problem doesn't arise if I comment the scanf statement.

- Security precautions: Please watch out for the following vulnerabilities.
Buffer Copy without Checking Size of Input ('Classic Buffer Overflow'): The product copies an input buffer to an output buffer without verifying that the size of the input buffer is less than the size of the output buffer, leading to a buffer overflow.

*/
