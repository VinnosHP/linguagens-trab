<template>
  <div class="container">
    <input id="input" placeholder="digite o codigo aqui: " class="Input">
    <div class="boxButton">
      <button @click=" this.clear() ">Limpar</button>
      <button @click=" this.main() ">Analizar</button>
    </div>
    <textarea name="results" id="results" ></textarea>
  </div>
</template>

<script>
// @ is an alias to /src
import HelloWorld from '@/components/HelloWorld.vue'

export default {
  name: 'HomeView',
  components: {
    HelloWorld
  },
  data(){
    return{
      alfabeto: ['a','b','c','d','e'],
      VALID: 'sentença válida:',
      aritimetic:  'operador aritmético',
      sentencaInvalida: 'ERRO => sentença inválida',
      simbuloInvalido: 'ERRO => símbolo(s) inválido(s)',
      aritimeticOperators: ['+','-','/','*'],
      controlCharacters: ['$',' '],
      tabelaT:[
        [ 11, 11,  6,  9, 11, 11],
        [ 11, 11, 11,  9, 11, 11 ],
        [  3, 11,  0,  7, 11, 11 ],
        [ 11,  4, 11, 11, 11, 11 ],
        [  5, 11, 11, 11, 11, 11 ],
        [ 11,  2, 11, 11, 11, 11 ],
        [ 11, 11,  0,  7, 11, 11 ],
        [ 11, 11, 11, 11,  1, 11 ],
        [ 11, 11, 11,  7, 11, 11 ],
        [ 11, 11, 11, 11,  8, 11 ],
        [ 11, 11, 11, 11, 11, 11 ],
      ],
      EF: [1,1,0,0,0,0,0,0,0,0,0],
    };
  },
  methods:{
    indiceSimbolo: function (simbolo) {
      if(simbolo == 'a') return 0
      else if(simbolo == 'b') return 1
      else if(simbolo == 'c') return 2
      else if(simbolo == 'd') return 3
      else if(simbolo == 'e') return 4
      else return 5
    },
    getSentencas: function (token){

      let sentencas = [];
      let sentenca = '';
      for (let i = 0; i < token.length; i++) {
        if(!this.controlCharacters.includes(token.charAt(i)) && !this.aritimeticOperators.includes(token.charAt(i))){
          sentenca +=  token[i];
        }else{
          sentenca +=  token[i];
          sentenca+= '$';
          sentencas.push(sentenca);
          sentenca = ''; 
        }
      }
      return sentencas;
    },
    inAlfhabeth: function(sentenca){
      for(let i = 0; i < sentenca.length - 1 ; i++  ){
        if (!this.alfabeto.includes(sentenca[i])) {
          return false;
        }
      }
      return true;
    },
    inAritimeticOperators: function(sentenca){
      for(let i = 0; i < sentenca.length - 1 ; i++  ){
        if (!this.aritimeticOperators.includes(sentenca[i])) {
          return false;
        }
      }
      return true;
    },
    inControlCharacters: function(sentenca){
      for(let i = 0; i < sentenca.length - 1 ; i++  ){
        if (!this.controlCharacters.includes(sentenca[i])) {
          return false;
        }
      }
      return true;
    },

    main:function(){
      console.clear();
      const input = document.getElementById('input');
      const results = document.getElementById('results');
      let toke = input.value;
      let estado = 2;
      
      const token = toke + "$";
      const sentencas = this.getSentencas(token);
      console.log(sentencas);

      
      for (const element of sentencas) {
        console.log(element.length);
        if(!this.inAlfhabeth(element)){
          for (let i = 0; i < element.length-1; i++) {
            if(element[i] == '/' || element[i] == '*' || element[i] == '+' || element[i]=='-'){
              results.value += `${this.aritimetic}${element[i]}\n`
            }
            else{
              if (element[i] != ' ') {
                results.value += `${this.simbuloInvalido}${element[i]}\n`
              }
            }
          }
        }
        else{
          for (let j = 0; j < element.length-1; j++) {
            let indice = this.indiceSimbolo(element[j]);
            estado = this.tabelaT[estado][indice];
          }
          if (this.EF[estado] == 1) {
            results.value += `${this.VALID}${element}\n`
          }
          else{
            results.value += `${this.sentencaInvalida}${element}\n`
          }
        }
      }
    
      
      
      /*for (const element of sentencas) {
        if(!this.inAlfhabeth(element)){
          results.value += `ERRO - Simbolo Invalido: ${element}\n`
        }
      }*/
      // console.log(retornos)

      // results.value += token
    },
    clear:function(){
      document.getElementById('input').value = '';
      document.getElementById('results').value = '';
    },
  },

}
</script>

<style scoped>
.container{
  display: flex;
  flex-direction: column;
  flex-wrap: nowrap;
  align-content: center;
  align-items: center;
  justify-content: center;
}

#results {
  width: 100%;
  min-height: 400px ;
  background-color: rgb(251, 218, 175);
  margin-top: 10px;
}
.Input{
  width: 400px;
  height: 50px;
  border-radius: 20px;
  border: 2px solid rgb(68, 48, 48);
  font: rgb(0, 0, 0) ;
  background-color: rgb(251, 218, 175);
  margin-bottom: 10px;
}
</style>