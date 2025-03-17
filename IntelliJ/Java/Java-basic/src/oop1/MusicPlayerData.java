package oop1;

public class MusicPlayerData {
    int volume = 0;
    boolean isOn = false;

        void on(){
            isOn = true;
            System.out.println("음악 플레이어를 시작합니다.");
        }

        void volumeUp(){
            volume++;
        }

        void  volumeDown(){
            volume--;
        }

        void showStatus(){
            System.out.println("볼륨 : " + volume + "상태" + isOn);
        }

        void off(){
            isOn = false;
            System.out.println("음악 플레이어를 종료합니다.");
        }
}
