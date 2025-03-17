package oop1;

public class MusicPlayerMain1 {
    public static void main(String[] args) {
        MusicPlayerData data = new MusicPlayerData();

        data.on();
        data.volumeUp();
        data.volumeUp();
        data.volumeDown();
        data.showStatus();
        data.off();
    }

}
