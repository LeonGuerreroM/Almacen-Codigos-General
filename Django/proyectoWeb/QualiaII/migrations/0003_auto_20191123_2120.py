# Generated by Django 2.2.4 on 2019-11-24 03:20

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('QualiaII', '0002_auto_20191122_2246'),
    ]

    operations = [
        migrations.AddField(
            model_name='tblproducto',
            name='costo',
            field=models.IntegerField(default=0),
        ),
        migrations.AlterField(
            model_name='tblproducto',
            name='precio',
            field=models.IntegerField(default=0),
        ),
    ]
