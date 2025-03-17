package ex.meassage;

public class SmsSender implements Sender {
    @Override
    public void sendMassage(String string) {
        System.out.println("SMS를 발송합니다 : " + string );
    }
}
