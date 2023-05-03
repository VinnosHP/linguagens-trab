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
      simboloInvalido: 'ERRO => símbolo(s) inválido(s)',
      aritimeticOperators: ['+','-','/','*'],
      endSentence: ['$','+','-','/','*',' '],
      tabelaT:[
        [ 10, 10,  6,  9, 10, 10 ],
        [ 10, 10, 10,  9, 10, 10 ],
        [  3, 10,  0,  7, 10, 10 ],
        [ 10,  4, 10, 10, 10, 10 ],
        [  5, 10, 10, 10, 10, 10 ],
        [ 10,  2, 10, 10, 10, 10 ],
        [ 10, 10,  0,  7, 10, 10 ],
        [ 10, 10, 10, 10,  1, 10 ],
        [ 10, 10, 10,  7, 10, 10 ],
        [ 10, 10, 10, 10,  8, 10 ],
        [ 10, 10, 10, 10, 10, 10 ],
      ],
      EF: [1,1,0,0,0,0,0,0,0,0,0],
    };
  },
  methods:{
    getSentencas: function (token){

      let sentencas = [];
      let sentenca = '';
      for (let i = 0; i < token.length; i++) {
        if(!this.endSentence.includes(token.charAt(i))){
          sentenca +=  token[i];
        }else{
          sentenca +=  token[i];
          sentenca += '$';
          sentencas.push(sentenca);
          sentenca = ''; 
        }
      }
      return sentencas;
    },
    inAlfhabeth: function(sentenca){
          
      for(let i = 0; i < sentenca.length - 1 ; i++  ){
        if (!this.alfabeto.includes(sentenca[i])) {
          // resposta = `Sentenca Invalida - Simbulo Invalido: ${sentenca}`
          return false;
        }
      }
      return true;
      
    },
    
    main:function(){
      console.clear();
      console.log(this.tabelaT[2][3])
      const input = document.getElementById('input');
      const results = document.getElementById('results');
      let toke = input.value;
      
      const token = toke + "$";
      const sentencas = this.getSentencas(token);
      console.log(sentencas);
      
      for (const element of sentencas) {
        if(!this.inAlfhabeth(element)){
          results.value += `ERRO - Simbolo Invalido: ${element}\n`
        }
      }
      // console.log(retornos)
      // results.value += token
    },
    clear:function(){
      document.getElementById('input').value = '';
      document.getElementById('results').value = '';
    },
    /*int indiceSimbolo(char simbolo){
    if(simbolo == 'a')
        return 0;
    else{
        if(simbolo == 'b')
            return 1;
        else{
            if(simbolo == 'c')
                return 2;
            else{
                if(simbolo == 'd')
                    return 3;
                else{
                    if(simbolo == 'e')
                        return 4;
                    else
                        return 5;
                }
            }
        }
    }
}*/
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