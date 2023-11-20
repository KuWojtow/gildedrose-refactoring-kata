#include "GildedRose.h"

GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}
GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}

void IncreaseQuality(Item& item){
    if (item.quality<50){
        item.quality ++;
    }
}
void DecreaseQuality(Item& item){
    if (item.quality>0){
        item.quality--;
    }
}
void UpdateB(Item& item){
    IncreaseQuality(item);
    if (item.sellIn<11){
        IncreaseQuality(item);
    }
    if (item.sellIn<6){
        IncreaseQuality(item);
    }
}

void GildedRose::updateQuality()
{
        for (int i = 0; i < items.size(); i++)
        {
            if (items[i].name == "Aged Brie")
            {
                IncreaseQuality(items[i]);
            }
            else if (items[i].name == "Backstage passes to a TAFKAL80ETC concert")
            {
                UpdateB(items[i]);
            }
            else if (items[i].name != "Sulfuras, Hand of Ragnaros")
            {
                DecreaseQuality(items[i]);
            }

            if (items[i].name != "Sulfuras, Hand of Ragnaros")
            {
                items[i].sellIn--;
            }

            if (items[i].sellIn < 0)
            {
                if (items[i].name == "Aged Brie")
                {
                    IncreaseQuality(items[i]);
                }
                else if (items[i].name != "Backstage passes to a TAFKAL80ETC concert")
                {
                    if (items[i].name != "Sulfuras, Hand of Ragnaros")
                    {
                        DecreaseQuality(items[i]);
                    }
                }
                else
                {
                    items[i].quality = 0;
                }
            }
        }
    }