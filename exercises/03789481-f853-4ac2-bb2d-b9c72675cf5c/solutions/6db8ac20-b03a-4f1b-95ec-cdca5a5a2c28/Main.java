/**
 * 
 */
//package topas.dcc.fc.up.pt;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

/**
 * @author pbrandao
 *
 */
public class Main {

	static ArrayList<Message> messagesReceived = new ArrayList<Message>();
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		//read input
		Scanner scan = new Scanner(System.in);
		int nrMsgs = scan.nextInt();
		scan.nextLine();
		for (int i = 0; i < nrMsgs; i++) {
			String msg = scan.nextLine();
			messagesReceived.add(new Message(msg));
		}
		scan.close();
			
		System.out.println(doYourStuff(messagesReceived));
	}

	private static String doYourStuff(ArrayList<Message> listOfMessages) {
		boolean newThings = true;
		while (newThings){
			// nothing new unless we view it
			newThings = false;
			for (int i =0; i< listOfMessages.size();i++) {
				for (int k =0; k< listOfMessages.size();k++) {
					Message newMessage = decode(listOfMessages.get(i),listOfMessages.get(k));
					if(newMessage !=null){
						if (!listOfMessages.contains(newMessage)){
							newThings = true;
							listOfMessages.add(newMessage);//we should just add it after the cycle, but what the heck...
						}
					}
				}
			}
		}
		ArrayList<Character> answer = new ArrayList<Character>();
		for (Message message : messagesReceived) {
			if(message.getSize()==1){
				answer.add(message.getMessage().toString().charAt(0));
			}
		}
		Collections.sort(answer);
		String answerSt= answer.toString();
		answerSt= answerSt.substring(1, answerSt.length()-1);
		if(answerSt.isEmpty()){
			return "erro";
		}
		return answerSt;
	}

	private static Message decode(Message messageToTest, Message existingMessage) {
		Message newDecoded = null;
		if(!messageToTest.message.equals(existingMessage.message)){ // not the same message
			if(existingMessage.containsAll(messageToTest)){ //we found something to decode
				newDecoded = existingMessage.extract(messageToTest);
			}
		}
		return newDecoded; 
	}

}

class Message {
	@Override
	public boolean equals(Object obj) {
		if(obj.getClass()!= Message.class){
			return false;
		}
		Message objMesg = (Message) obj;
		
		return objMesg.message.equals(this.message);
	}

	ArrayList<Character> data;
	String message;
	
	public Message(String value) {
		setThis(value);
	}
	
	private void setThis(String value) {
		message = value;
		data = new ArrayList<Character> ();
		for (char c : message.toCharArray()) {
			data.add(c);
		}		
	}
	
	private void setThis(ArrayList<Character> value) {
		StringBuffer stB = new StringBuffer();
		for (Character c : value) {
			stB.append(c);
		}
		setThis(stB.toString());
	}
	
	public Message(ArrayList<Character> clonedData) {
		setThis(clonedData);
	}

	public ArrayList<Character> getData() {
		return data;
	}
	
	public boolean containsAll(Message newMessage) {
		return data.containsAll(newMessage.getData());
	}
	
	public int getSize(){
		return data.size();
	}

	public String getMessage() {
		return message;
	}

	public Message extract(Message messageToTest) {
		ArrayList<Character> clonedData = new ArrayList<Character>();
		clonedData.addAll(data);
		clonedData.removeAll(messageToTest.getData());
		Message newMsg = new Message(clonedData);
		return newMsg;
	}
	
}