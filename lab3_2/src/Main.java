public class Main {

    static int iloscZwierzat = 2;
    public static void main(String[] args){
        Schronisko schronisko = new Schronisko(iloscZwierzat);
        for(int i = 0 ; i < iloscZwierzat; i++){
            new Kot(i,1500,schronisko).start();
        }
    }
}
