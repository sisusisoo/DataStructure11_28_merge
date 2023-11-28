# include <stdio.h>
# define MAX_SIZE 20

int sorted[MAX_SIZE]; // 추가적인 공간이 필요
//카운트 변수들 
int compare_count, move_count;
int c_total, m_total;
int once;//처음 한번의 싸이클에서만 출력되게 



//정렬현황용
void print_all(int list[]) {
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d->", list[i]);

    }
    printf("\n");
}

// i: 정렬된 왼쪽 리스트에 대한 인덱스
// j: 정렬된 오른쪽 리스트에 대한 인덱스
// k: 정렬될 리스트에 대한 인덱스
/* 2개의 인접한 배열 list[left...mid]와 list[mid+1...right]의 합병 과정 */
/* (실제로 숫자들이 정렬되는 과정) */
void merge(int list[], int left, int mid, int right) {
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;

    /* 분할 정렬된 list의 합병 */
    while (i <= mid && j <= right) {

        compare_count++;
        move_count++;
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }

    // 남아 있는 값들을 일괄 복사
    if (i > mid) {
        for (l = j; l <= right; l++)
            sorted[k++] = list[l];
        move_count++;
    }
    // 남아 있는 값들을 일괄 복사
    else {
        for (l = i; l <= mid; l++)
            sorted[k++] = list[l];
        move_count++;
    }
    
    // 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
    for (l = left; l <= right; l++) {
        //이거는 그저 임시 데이터를 옮기는것에 불과 -> 카운트로 취급 x
        list[l] = sorted[l];
       // move_count++;
    }
   if(once==0) print_all(list);
}

// 합병 정렬
void merge_sort(int list[], int left, int right) {
    int mid;

    if (left < right) {
        mid = (left + right) / 2; // 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
            merge_sort(list, left, mid); // 앞쪽 부분 리스트 정렬 -정복(Conquer)
        merge_sort(list, mid + 1, right); // 뒤쪽 부분 리스트 정렬 -정복(Conquer)
        merge(list, left, mid, right); // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine)
    }
}

void  mergeCycle() {
    compare_count = 0;
    move_count = 0;

    int i;
    int n = MAX_SIZE;
    int list[MAX_SIZE];

    if (once == 0)printf("초기값\n");
    for (i = 0; i < n; i++) {
        list[i] = rand() % 100;
        if (once == 0)printf("%d->", list[i]);

    }
    if (once == 0) printf("\n");
    merge_sort(list,0,n-1);

    if (once == 0) {
        printf("compare count : %d\n", compare_count);
        printf("move count : %d\n", move_count);
    }
    //printf("rand %d", rand() % 100);
    c_total += compare_count;
    m_total += move_count;


}

void main() {


    srand(time(NULL));


    mergeCycle();

    //카운트 초기화 
    compare_count = 0;
    move_count = 0;

    //이 뒤에 정렬들은 출력 되지 않게 함 
    once = 1;


    for (int i = 0; i < 19; i++) {
        mergeCycle();
    }


    //20번 평균 
    printf(" compare count avg:%f\n ", (float)c_total / (float)20);
    printf("move count avg:%f\n ", (float)m_total / (float)20);
}