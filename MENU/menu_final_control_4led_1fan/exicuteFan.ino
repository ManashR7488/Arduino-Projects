void exicuteFan(){
  if( a == 2 && b == 1){
    digitalWrite(fan,HIGH);
  }
  if(a == 2 && b == 2){
    digitalWrite(fan,LOW);
  }
}