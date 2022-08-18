import { data } from '../../../test_data/chart_types_eu.mjs';


const testSteps = [
    chart => chart.animate({
        data: Object.assign(data, {
            filter: record =>
                record.Country == 'Austria' ||
                record.Country == 'Belgium' ||
                record.Country == 'Bulgaria' ||
                record.Country == 'Cyprus' ||
                record.Country == 'Czechia' ||
                record.Country == 'Denmark' ||
                record.Country == 'Estonia' ||
                record.Country == 'Greece' ||
                record.Country == 'Germany' ||
                record.Country == 'Spain' ||
                record.Country == 'Finland' ||
                record.Country == 'France' ||
                record.Country == 'Croatia' ||
               record.Country == 'Hungary'
        }),
        config: {
            channels: {
                x: { set: ['Year'] },
                y: { set: ['Country', 'Value 2 (+)'] },
                color: { set: ['Country'] },
            },
            title: 'Stacked Column Chart',
            geometry: 'rectangle',
            coordSystem: 'polar',
            legend: null
        },
        style: {
            plot: {
                paddingLeft: 100,
                yAxis: {
                    label: {
                       paddingRight: 10,
                        fontSize: 13
                    }
                }
            }
        }
    }),

    chart => chart.animate({
        config: {
            channels: {
                x: { set: ['Value 2 (+)'] },
                noop: { set: ['Year'] },
                y: { set: ['Country'] },
                color: { set: ['Country'] },
            },
            title: 'Spider Line Fake',
            geometry: 'line',
            orientation: 'vertical',
            split: false,
        }
    },
       {       
        easing: 'cubic-bezier(0.65,0,0.65,1)',
            coordSystem: {
                delay: 0,
                duration: 1,
   //                easing: 'linear' 
        },
        geometry: { 
            delay: 0, 
            duration: 0.5, 
   //                easing: 'linear' 
        },
        x: {
            delay: 0.25,
            duration: 0.75,
   //               easing: 'ease-in'
        }, 
        y: {
           delay: 0,
           duration: 0.75,
   //                easing: 'cubic-bezier(65,0,65,1)'
            }
        }
    ),

    chart => chart.animate({
    config: {
        channels: {
            x: { set: ['Year'] },
            y: { set: ['Country', 'Value 2 (+)'] },
            color: { set: ['Country'] },
        },
        title: 'Stacked Column Chart',
        geometry: 'rectangle',
        legend: null
    },
    style: {
        plot: {
            paddingLeft: 100,
            yAxis: {
                label: {
                   paddingRight: 10,
                    fontSize: 13
                }
            }
        }
    }
},
 {       
    easing: 'cubic-bezier(0.65,0,0.65,1)',
     coordSystem: {
         delay: 0,
         duration: 1,
//                easing: 'linear' 
     },
     geometry: { 
        delay: 0.5, 
        duration: 0.5, 
//                easing: 'linear' 
    },
    x: {
        delay: 0,
        duration: 0.75,
//               easing: 'ease-in'
    }, 
    y: {
        delay: 0.25,
        duration: 0.75,
//                easing: 'cubic-bezier(65,0,65,1)'
     }
 }
),

];

export default testSteps;