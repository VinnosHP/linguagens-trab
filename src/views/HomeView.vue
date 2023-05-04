<template>
  <div class="container">
    <input id="input" placeholder="digite o codigo aqui: " value="+ccccc dedede t" class="Input">
    <div class="boxButton">
      <button @click=" this.clear()">Limpar</button>
      <button @click=" this.main()">Analizar</button>
    </div>
    <textarea name="results" id="results" ></textarea>
  </div>
</template>

<script>
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
      separadores: ['+','-','/','*','$',' '],


      tabelaT:[
    //     A|  B|  C|  D|  E| Er
  /* 0*/[ 10, 10,  6,  9, 10, 10 ],
  /* 1*/[ 10, 10, 10,  9, 10, 10 ],
  /* 2*/[  3, 10,  0,  7, 10, 10 ],
  /* 3*/[ 10,  4, 10, 10, 10, 10 ],
  /* 4*/[  5, 10, 10, 10, 10, 10 ],
  /* 5*/[ 10,  2, 10, 10, 10, 10 ],
  /* 6*/[ 10, 10,  0,  7, 10, 10 ],
  /* 7*/[ 10, 10, 10, 10,  1, 10 ],
  /* 8*/[ 10, 10, 10,  7, 10, 10 ],
  /* 9*/[ 10, 10, 10, 10,  8, 10 ],
  /*10*/[ 10, 10, 10, 10, 10, 10 ],
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
      console.log(token)
      let sentencas = [];
      let sentenca = '';
      
      for (let i = 0; i < token.length; i++) {
        // console.log(token[i])
        if(this.separadores.includes(token[i])){
          // if (token[i] !== ' '){
            console.log('ta no else',token[i]);

            console.log(token[i]);
            sentenca +=  token[i];
            // sentenca += '$';
            sentencas.push(sentenca);
            sentenca = ''; 
          // }
        }else{
          sentenca +=  token[i]
        }
      }
      return sentencas;
    },
    inAlfhabeth: function(sentenca){
          
      for(let i = 0; i < sentenca.length - 2 ; i++  ){
        if (!this.alfabeto.includes(sentenca[i])) {
          return false;
        }
      }
      return true;
      
    },
    generic: function(sentencas, results){
      let estado = 2;
      for (const element of sentencas) {
        if(this.inAlfhabeth(element)){
          let j=0;
           while (element[j] != '$') {
             let indice = this.indiceSimbolo(element[j]);
             estado = this.tabelaT[estado][indice];
             j++;
           }
          if (this.EF[estado] == 1) results.value += `${this.VALID} ${element}\n`;
          else results.value += `${this.sentencaInvalida} ${element}\n`;
          estado = 2;
         }
         else{
           for (let i = 0; i < element.length-1; i++) {
             if (this.aritimeticOperators.includes(element[i]))
                results.value += `${this.aritimetic} ${element[i]}\n`
             else{
                if(element[i] != ' ') results.value += `${this.simbuloInvalido} ${element[i]}\n`
             }
           }
         }
      }
    },

    main:function(){
    

      console.clear();
      const input = document.getElementById('input');
      const results = document.getElementById('results');
      let toke = input.value;
      
      const token = toke+"$" ;
      const sentencas = this.getSentencas(token);
      console.log(sentencas);
      this.generic(sentencas, results);
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