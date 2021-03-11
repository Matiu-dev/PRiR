public class Schronisko {
    static int SCHRONISKO = 1;
    static int ZABAWA = 5;

    int ilosc_zwierzat;
    int ilosc_zajetych;

    Schronisko(int ilosc_zwierzat){
        this.ilosc_zwierzat = ilosc_zwierzat;
        ilosc_zajetych=0;
    }

    synchronized int karmienie(int numer){
        try{
            Thread.currentThread().sleep(1000);
        } catch(Exception ie){ }

        ilosc_zajetych++;
        System.out.println("Kot "+ numer + " może odpocząć, ilosc zajetych miejsc " + ilosc_zajetych);

        return SCHRONISKO;
    }

    synchronized int zabawa(int numer){
        ilosc_zajetych--;
        System.out.println("Kot " + numer +" może się bawić ");
        return ZABAWA;
    }

}
