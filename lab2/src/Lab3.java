public class Lab3 {

    public static void main(String[] args){

        M_Trapezow m_Trapezow = new M_Trapezow(0.1,1.1,30);
        m_Trapezow.start();

        M_Simpsona m_Simpsona = new M_Simpsona(0.1,1.1,30);
        m_Simpsona.start();

        M_Prostokatow m_Prostokatow = new M_Prostokatow(0.1, 1.1, 16);
        m_Prostokatow.start();

        while(m_Trapezow.isAlive() && m_Simpsona.isAlive() && m_Prostokatow.isAlive())
        try {
            Thread.sleep (10); // Sleep for 10 milliseconds
        } catch (InterruptedException e) {

        }

        System.out.println("M trapezow " + m_Trapezow.wynik);
        System.out.println("M_Simpsona " + m_Simpsona.wynik);
        System.out.println("M_Prostokatow " + m_Prostokatow.wynik);

    }
}
