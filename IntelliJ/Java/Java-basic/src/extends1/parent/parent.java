package extends1.parent;

public class parent {

    public int publicValue;
    protected int protectedValue;
    int defaultValue;
    private int privateValue;

    public void setPublicValue() {
        System.out.println("parent.setPublicValue");
    }

    protected void setProtectedValue() {
        System.out.println("parent.setProtectedValue");
    }

    void setDefaultValue() {
        System.out.println("parent.setDefaultValue");
    }

    private void setPrivateValue() {
        System.out.println("parent.setPrivateValue");
    }

    public void printParent() {
        System.out.println("부모 메서드 안");
        System.out.println("publicValue = " + publicValue);
        System.out.println("protectedValue = " + protectedValue);
        System.out.println("defaultValue = " + defaultValue);
        System.out.println("privateValue = " + privateValue);

        setDefaultValue();
        setPrivateValue();
    }
}
