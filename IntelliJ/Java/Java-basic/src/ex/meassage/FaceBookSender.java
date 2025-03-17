package ex.meassage;

public class FaceBookSender implements Sender{
    @Override
    public void sendMassage(String string) {
        System.out.println("페이스북에 발송합니다 : " + string);
    }
}
