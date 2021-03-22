// University of Seoul. Dept of Computer Science.
// 2018430021 김형철
// EX3_3

public class EX3_3 {
    //3중 for문을 이용하여 주어진 조건에 맞는 직각삼각형 변의 길이 출력.
    public static void main(String[] args) {
        for (int i = 1; i < 100; i++)
            for (int j = 1; j < 100; j++)
                for (int k = 1; k < 100; k++)
                    if (i * i + j * j == k * k || j * j + k * k == i * i || i * i + k * k == j * j)
                        System.out.println(i + " " + j + " " + k);
    }
}
