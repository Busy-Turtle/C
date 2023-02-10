#include <stdio.h>

int main(void) {

   int bowl[22] = {0};
   int frame[11] = {0};
   int totalScore = 0;

   for(int i=1;i<11;++i){
      if (i <= 9) {
         for (int j = 2 * i - 1; j < 2 * i + 1; ++j) {
            
            printf("This is %d - %d Try\n",i,(j%2 ? 1 : 2));

            scanf("%d", &bowl[j]);

            if (i >= 3 && j % 2 == 1 && bowl[j - 4] == 10 && bowl[j - 2] == 10) {
               frame[i - 2] = bowl[j - 4] + bowl[j - 2] + bowl[j]; // 경우의수1. 스트라이크 3연속일때 
               totalScore = totalScore + frame[i - 2];
               printf("frame%d score:%d totalScore: %d\n", i - 2, frame[i - 2], totalScore);
            }

            if (i >= 2 && j % 2 == 1 && bowl[j - 2] != 10 && (bowl[j - 2] + bowl[j - 1]) == 10) {
               frame[i - 1] = bowl[j - 2] + bowl[j - 1] + bowl[j];  // 경우의수2. 전 프레임이 스페어일때
               totalScore = totalScore + frame[i - 1];
               printf("frame%d score:%d totalScore: %d\n", i - 1, frame[i - 1], totalScore);
            }

            if (i >= 2 && j % 2 == 0 && bowl[j - 3] == 10 && bowl[j - 1] != 10) {
               frame[i - 1] = bowl[j - 3] + bowl[j - 1] + bowl[j]; //경우의수3. 전 프레임이 스트라이크일때
               totalScore = totalScore + frame[i - 1];
               printf("frame%d score:%d totalScore: %d\n", i - 1, frame[i - 1], totalScore);
            }

            if (j % 2 == 1 && bowl[j] == 10 && j != 21) {
               break;    // Strike일때 빠져나온다 (현재프레임 점수가 계산되선안됨)
            }
            else if (j % 2 == 0 && bowl[j - 1] + bowl[j] == 10) {
               break;    // spare 일때 빠져나온다 (현재프레임 점수가 계산되선안됨)
            }
            else if (j % 2 == 0 && bowl[j - 1] + bowl[j] != 10) {
               frame[i] = bowl[j - 1] + bowl[j];
               totalScore = totalScore + frame[i];
               printf("frame%d score:%d totalScore: %d\n", i, frame[i], totalScore);
            }

         }
      }

      if (i == 10) {
         printf("This is 10-1 Try\n");
         scanf("%d", &bowl[19]);

         if (bowl[15] == 10 && bowl[17]== 10) {
            frame[i - 2] = bowl[15] + bowl[17] + bowl[19]; // 경우의수1. 스트라이크 3연속일때 
            totalScore = totalScore + frame[i - 2];
            printf("frame%d score:%d totalScore: %d\n", i - 2, frame[i - 2], totalScore);
           }

         if (bowl[17] != 10 && (bowl[17] + bowl[18]) == 10) {
            frame[i - 1] = bowl[17] + bowl[18] + bowl[19];  // 경우의수2. 전 프레임이 스페어일때
            totalScore = totalScore + frame[i - 1];
            printf("frame%d score:%d totalScore: %d\n", i - 1, frame[i - 1], totalScore);
           }

         printf("This is 10-2 Try\n");
         scanf("%d", &bowl[20]);

         if (bowl[17] == 10) {
            frame[i - 1] = bowl[17] + bowl[19] + bowl[20]; //경우의수3. 전 프레임이 스트라이크일때
            totalScore = totalScore + frame[i - 1];
            printf("frame%d score:%d totalScore: %d\n", i - 1, frame[i - 1], totalScore);
           }
           
           
           
	      if(bowl[19]==10){
         printf("This is 10-3 Try\n");
         scanf("%d", &bowl[21]);

         frame[10] = bowl[19] + bowl[20] + bowl[21];
         totalScore = totalScore + frame[10];
         printf("frame10 score:%d totalScore: %d\n",frame[10], totalScore);
         } else if(bowl[19]!=10 && bowl[19]+bowl[20]==10) {
         		printf("This is 10-3 Try\n");
         		scanf("%d", &bowl[21]);

         		frame[10] = bowl[19] + bowl[20] + bowl[21];
         		totalScore = totalScore + frame[10];
         		printf("frame10 score:%d totalScore: %d\n",frame[10], totalScore);
           	 } else { 
           	 		frame[10] = bowl[19] + bowl[20] + bowl[21];
         		totalScore = totalScore + frame[10];
         		printf("frame10 score:%d totalScore: %d\n",frame[10], totalScore);
           	 		}
       }   
   }

   return 0;
}
