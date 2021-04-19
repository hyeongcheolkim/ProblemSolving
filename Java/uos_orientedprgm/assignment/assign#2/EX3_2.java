// University of Seoul. Dept of Computer Science.
// 2018430021 김형철
// EX3_2

public class EX3_2 {
    public static void main(String[] args) throws Exception {

        //2부터 100까지 true값을 갖는 배열 생성.
        boolean[] arr = new boolean[100+1];
        for (int i = 2; i <= 100; i++)
            arr[i] = true;
        //만약 소수의 배수라면, false로 바꾼다.
        for (int i = 2; i*i < 100; i++)
            for (int j = i + i; j <= 100; j += i)
                arr[j] = false;
        //true인 값들만 출력
        for (int i = 2; i <= 100; i++)
            if(arr[i])
                System.out.print(i+" ");
    }
}
