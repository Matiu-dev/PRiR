import java.util.Random;

public class Kot extends Thread{

    static int SCHRONISKO = 1;
    static int KARM = 2;
    static int ZABAWA = 5;
    static int JEDZ = 500;
    static int REZERWA = 250;

    int numer;
    int jedzenie;
    int stan;
    Schronisko s;
    Random rand;

    public Kot(int numer, int jedzenie, Schronisko s){
        this.numer = numer;
        this.jedzenie = jedzenie;
        this.stan=ZABAWA;
        this.s=s;
        rand = new Random();
    }

    public void run(){
        while(true){
            if(stan == SCHRONISKO){
                if(rand.nextInt(2)==1){
                    System.out.println("Kot " + numer + " zgłasza się do zabawy");
                    jedzenie = JEDZ;
                    stan=ZABAWA;
                    stan=s.zabawa(numer);
                }else{
                    System.out.println("Pojem sobie jeszcze troche");
                }
            }else if(stan==ZABAWA){
               jedzenie-=rand.nextInt(500);
               System.out.println("Kot " + numer + " bawi sie, ilosc energii " + jedzenie);

               if(jedzenie <= REZERWA){
                   stan = KARM;
               }else try{
                   sleep(rand.nextInt(1000));
               }catch (Exception e){

               }
            }else if(stan==KARM){
                System.out.println("Kot " + numer + " prosi o jedzenie, ilosc jedzenia " + jedzenie );
                stan=s.karmienie(numer);
            }
        }
    }
}
