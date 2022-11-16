import { data } from '../../../../../test_data/chart_types_eu.mjs';


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
                x: { set: ['Year','Value 3 (+)'] },
                y: { set: ['Country', 'Value 2 (+)'] },
                color: { set: 'Country' }
            },
            title: 'Mekko Chart',
            geometry: 'rectangle',
            orientation: 'horizontal'
        } 
    }),


    chart => chart.animate({
        config: {
            channels: {
                x: { set: ['Year', 'Value 3 (+)'] },
                y: { set: 'Country' },
                color: { set: 'Country' }
            },
            title: 'Bar Remove Conti & Change Orient.'
        }
    }
    ),

    
    chart => chart.animate({
    config: {
        channels: {
            x: { set: ['Joy factors', 'Value 3 (+)'] },
            y: { set: 'Country' },
            color: { set: 'Country' }
        },
        title: 'Bar Change Disc',
        orientation: 'vertical'
    } 
},
       {
                duration: 0
        }

),
chart => chart.animate({
    config: {
        channels: {
            x: { set: ['Joy factors', 'Value 3 (+)'] },
            y: { set: ['Country', 'Value 1 (+)'] },
            color: { set: 'Country' }
        },
        title: 'Mekko Chart Add Conti & Change Orient.',
        orientation: 'horizontal'
    } 
}

)];

export default testSteps;