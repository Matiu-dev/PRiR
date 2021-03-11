//        Napisz program w Javie, który połączy wszystkie programy dotyczące problemu myślących
//        i jedzących Filozofów z wykładu 3 w jednym kodzie. Program powinien w trakcie uruchamiania
//        posiadać następujące opcje:
//        - wybór jednego z 3 wariantów do uruchomienia,
//        - sterowanie liczbą filozofów w symulacji (od 2 do 100).

import java.util.Scanner;
import java.util.concurrent.Semaphore;

public class Main{
    public static void main(String[] args){

        int liczbaFilozofow;
        int nrMetody;

        Scanner scanner = new Scanner(System.in);

        do{
            System.out.println("Podaj liczbe filozofów od 2 do 100");
            liczbaFilozofow = Integer.parseInt(scanner.nextLine());

        }while(liczbaFilozofow > 100 || liczbaFilozofow < 2);

        System.out.println("liczba filozofów to: " + liczbaFilozofow);


        System.out.println("Podaj numer metody od 1-3");

        do{
            System.out.println("Podaj numer metody od 1 do 3");
            nrMetody = Integer.parseInt(scanner.nextLine());
        }while(nrMetody > 3 || nrMetody < 1);

        System.out.println("Numer metody to: " + nrMetody);

        if(nrMetody == 1){
            for ( int i =0; i<liczbaFilozofow; i++) {
                Filozof.widelec[ i ]=new Semaphore( 1 ) ;
            }

            for (int i = 0; i<liczbaFilozofow; i++) {
                new Filozof(i).start();
            }
        }else if(nrMetody == 2){
            for ( int i =0; i<liczbaFilozofow; i++) {
                Filozof2.widelec[ i ]=new Semaphore( 1 ) ;
            }

            for (int i = 0; i<liczbaFilozofow; i++) {
                new Filozof2(i).start();
            }
        }else if(nrMetody == 3){
            for ( int i =0; i<liczbaFilozofow; i++) {
                Filozof3.widelec[ i ]=new Semaphore( 1 ) ;
            }

            for (int i = 0; i<liczbaFilozofow; i++) {
                new Filozof3(i).start();
            }
        }



}
}
