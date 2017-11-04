int adelante = 5; 
int izquierda = 6; 
int derecha = 9; 
int retroceso = 10; 
int velo = 255;            // Velocidad de los motores (0-255)
int estado = 'g';         // inicia detenido

void setup()  { 
  Serial.begin(9600);    // inicia el puerto serial para comunicacion con el Bluetooth
  pinMode(derecha, OUTPUT);
  pinMode(retroceso, OUTPUT);
  pinMode(adelante, OUTPUT);
  pinMode(izquierda, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(retroceso, HIGH);
  digitalWrite(izquierda, HIGH);
  digitalWrite(derecha, HIGH);
  digitalWrite(adelante, HIGH);
  digitalWrite(13, LOW);
} 

void loop()  { 
  if(Serial.available()>0) {      // lee el bluetooth y almacena en estado
    estado = Serial.read();
  }
  if(estado=='a'){           // Boton desplazar al Frente
    digitalWrite(retroceso, HIGH);     
    digitalWrite(izquierda, HIGH); 
    digitalWrite(derecha, LOW);  
    digitalWrite(adelante, LOW);       
  }
  if(estado=='b'){          // Boton atras 
    digitalWrite(retroceso, LOW);     
    digitalWrite(izquierda, LOW); 
    digitalWrite(derecha, HIGH);  
    digitalWrite(adelante, HIGH);      
  }
  if(estado=='c'){         // Boton Parar
    digitalWrite(retroceso, HIGH);     
    digitalWrite(izquierda, HIGH); 
    digitalWrite(derecha, HIGH);    
    digitalWrite(adelante, HIGH); 
  }
  if(estado=='d'){          // Boton DER
    digitalWrite(retroceso, HIGH);     
    digitalWrite(izquierda, LOW);
    digitalWrite(derecha, HIGH); 
    digitalWrite(adelante, LOW);
     
  } 

  if(estado=='e'){          // Boton izquierda
    digitalWrite(retroceso, LOW);     
    digitalWrite(izquierda, HIGH);
    digitalWrite(derecha, LOW); 
    digitalWrite(adelante, HIGH);        
  }
  if(estado=='f'){          // ARMA ENCENDIDA
    digitalWrite(13, HIGH);      
  }

  if(estado=='g'){          // ARMA APAGADA
    digitalWrite(13, LOW);      
  }
  
  
}


