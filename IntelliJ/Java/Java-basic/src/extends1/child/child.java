package extends1.child;

public class child extends extends1.parent.parent{

    public void call() {
        publicValue = 1;
        protectedValue = 1;
        //defaultValue =1;
        //privateValue =1;

        setPublicValue();
        setProtectedValue();
        //setDefaultValue();
        //setPrivateValue();

        printParent();
    }
}
