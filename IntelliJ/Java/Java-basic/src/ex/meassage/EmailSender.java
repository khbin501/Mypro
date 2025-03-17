package ex.meassage;

public class EmailSender implements Sender {
    @Override
    public void sendMassage(String string) {
        System.out.println("메일을 발송합니다 : "+ string);
    }
}
