# Generated by Django 2.2.4 on 2019-11-26 06:20

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('QualiaII', '0004_auto_20191125_0217'),
    ]

    operations = [
        migrations.AddField(
            model_name='tbllistanegra',
            name='marca',
            field=models.CharField(default='---', max_length=30),
        ),
        migrations.AddField(
            model_name='tbllistanegra',
            name='nombre',
            field=models.CharField(default='---', max_length=30),
        ),
        migrations.AddField(
            model_name='tbllistanegra',
            name='tipo',
            field=models.CharField(default='---', max_length=20),
        ),
    ]