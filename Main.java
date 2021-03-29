package homework;

public class Main {
    public static void main(String [] args){
        Fan fan1=new Fan();
        Fan fan2=new Fan();
        fan1.setOn(true);
        fan1.setSpeed(Fan.FAST);
        fan1.setRadius(10);
        fan1.setColor("yellow");
        fan2.setOn(false);
        fan2.setSpeed(Fan.MEDIUM);
        fan2.setRadius(5);
        fan2.setColor("blue");

        System.out.println("fan1: "+fan1.toString());
        System.out.println("fan2: "+fan2.toString());
    }
}

class Fan{

    static final int SLOW=1;
    static final int MEDIUM=2;
    static final int FAST=3;
    private int speed=SLOW;
    private boolean on=false;
    private double radius=5;
    private String color="blue";

    public void setSpeed(int sp){
        this.speed=sp;
    }
    public void setOn(boolean status){
        this.on=status;
    }
    public void setRadius(double ra){
        this.radius=ra;
    }
    public void setColor(String col){
        this.color=col;
    }

    Fan(){
        speed=SLOW;
        on=false;
        radius=5;
        color="blue";
    }

    public String toString(){
        String status;
        if(this.on) status="the speed is: "+this.speed+"    the color is: "+this.color+"    the radius is: "+this.radius;
        else status="fan is off "+"     the color is: "+this.color+"    the radius is: "+this.radius;
        return status;
    }
}
